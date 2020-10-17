## 주의사항

```c
...

// Load a BMFont file (AngelCode font file)
// REQUIRES: strstr(), sscanf(), strrchr(), memcpy()
static Font LoadBMFont(const char *fileName) 
{
    #define MAX_BUFFER_SIZE     256

    Font font = { 0 };

    char buffer[MAX_BUFFER_SIZE] = { 0 };
    char *searchPoint = NULL;

    int fontSize = 0;
    int charsCount = 0;
    
    int imWidth = 0;
    int imHeight = 0;
    char imFileName[129];

    int base = 0;   // Useless data

    char *fileText = LoadFileText(fileName);

    if (fileText == NULL) return font;

    char *fileTextPtr = fileText;
    
    // NOTE: We skip first line, it contains no useful information
    int lineBytes = GetLine(fileTextPtr, buffer, MAX_BUFFER_SIZE);
    fileTextPtr += (lineBytes + 1);

    // Read line data
    lineBytes = GetLine(fileTextPtr, buffer, MAX_BUFFER_SIZE);
    searchPoint = strstr(buffer, "lineHeight");
    sscanf(searchPoint, "lineHeight=%i base=%i scaleW=%i scaleH=%i", &fontSize, &base, &imWidth, &imHeight);
    fileTextPtr += (lineBytes + 1);

    TRACELOGD("FONT: [%s] Loaded font info:", fileName);
    TRACELOGD("    > Base size: %i", fontSize);
    TRACELOGD("    > Texture scale: %ix%i", imWidth, imHeight);

    lineBytes = GetLine(fileTextPtr, buffer, MAX_BUFFER_SIZE);
    searchPoint = strstr(buffer, "file");
    sscanf(searchPoint, "file=\"%128[^\"]\"", imFileName);
    fileTextPtr += (lineBytes + 1);

    TRACELOGD("    > Texture filename: %s", imFileName);

    lineBytes = GetLine(fileTextPtr, buffer, MAX_BUFFER_SIZE);
    searchPoint = strstr(buffer, "count");
    sscanf(searchPoint, "count=%i", &charsCount);
    fileTextPtr += (lineBytes + 1);

    TRACELOGD("    > Chars count: %i", charsCount);

    // Compose correct path using route of .fnt file (fileName) and imFileName
    char *imPath = NULL;
    char *lastSlash = NULL;

    lastSlash = strrchr(fileName, '/');
    if (lastSlash == NULL) lastSlash = strrchr(fileName, '\\');

    if (lastSlash != NULL)
    {
        // NOTE: We need some extra space to avoid memory corruption on next allocations!
        imPath = RL_CALLOC(TextLength(fileName) - TextLength(lastSlash) + TextLength(imFileName) + 4, 1);
        memcpy(imPath, fileName, TextLength(fileName) - TextLength(lastSlash) + 1);
        memcpy(imPath + TextLength(fileName) - TextLength(lastSlash) + 1, imFileName, TextLength(imFileName));
    }
    else imPath = imFileName;

    TRACELOGD("    > Image loading path: %s", imPath);

    Image imFont = LoadImage(imPath);

    if (imFont.format == UNCOMPRESSED_GRAYSCALE)
    {
        // Convert image to GRAYSCALE + ALPHA, using the mask as the alpha channel
        Image imFontAlpha = {
            .data = calloc(imFont.width*imFont.height, 2),
            .width = imFont.width,
            .height = imFont.height,
            .format = UNCOMPRESSED_GRAY_ALPHA,
            .mipmaps = 1
        };

        for (int p = 0, i = 0; p < (imFont.width*imFont.height*2); p += 2, i++)
        {
            ((unsigned char *)(imFontAlpha.data))[p] = 0xff;
            ((unsigned char *)(imFontAlpha.data))[p + 1] = ((unsigned char *)imFont.data)[i];
        }
        
        UnloadImage(imFont);
        imFont = imFontAlpha;
    }

    font.texture = LoadTextureFromImage(imFont);

    if (lastSlash != NULL) RL_FREE(imPath);

    // Fill font characters info data
    font.baseSize = fontSize;
    font.charsCount = charsCount;
    font.chars = (CharInfo *)RL_MALLOC(charsCount*sizeof(CharInfo));
    font.recs = (Rectangle *)RL_MALLOC(charsCount*sizeof(Rectangle));

    int charId, charX, charY, charWidth, charHeight, charOffsetX, charOffsetY, charAdvanceX;

    for (int i = 0; i < charsCount; i++)
    {
        lineBytes = GetLine(fileTextPtr, buffer, MAX_BUFFER_SIZE);
        sscanf(buffer, "char id=%i x=%i y=%i width=%i height=%i xoffset=%i yoffset=%i xadvance=%i",
                       &charId, &charX, &charY, &charWidth, &charHeight, &charOffsetX, &charOffsetY, &charAdvanceX);
        fileTextPtr += (lineBytes + 1);

        // Get character rectangle in the font atlas texture
        font.recs[i] = (Rectangle){ (float)charX, (float)charY, (float)charWidth, (float)charHeight };

        // Save data properly in sprite font
        font.chars[i].value = charId;
        font.chars[i].offsetX = charOffsetX;
        font.chars[i].offsetY = charOffsetY;
        font.chars[i].advanceX = charAdvanceX;

        // Fill character image data from imFont data
        font.chars[i].image = ImageFromImage(imFont, font.recs[i]);
    }

    UnloadImage(imFont);
    RL_FREE(fileText);

    if (font.texture.id == 0)
    {
        UnloadFont(font);
        font = GetFontDefault();
        TRACELOG(LOG_WARNING, "FONT: [%s] Failed to load texture, reverted to default font", fileName);
    }
    else TRACELOG(LOG_INFO, "FONT: [%s] Font loaded successfully", fileName);

    return font;
}

...
```

> `raylib v3.1-dev`에서는 `BMFont`를 불러올 때 텍스처 파일을 단 한 개만 불러온다.
따라서 `BMFont`의 `Export options [T]`에서 `Texture`의 크기를 충분히 크게 설정하여,
텍스처 파일이 하나만 생성될 수 있도록 한다.