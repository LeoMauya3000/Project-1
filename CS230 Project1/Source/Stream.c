#include "stdafx.h"
#include "Stream.h"
#include "Vector2D.h"
#include "Trace.h"







static FILE* streamFile;
static int integerRead;
static float floatRead;

Stream StreamOpen(const char* filePath)
{

	fopen_s(&streamFile, filePath, "rt");

	if (streamFile == NULL)
	{
		char errorMsg[256];
		strerror_s(errorMsg, sizeof(errorMsg), errno);
		TraceMessage("Error: StreamOpen could not open file %s; %s", filePath, errorMsg);
		return NULL;
	}
	else
	{
		return streamFile;
	}
}

int StreamReadInt(Stream stream)
{
	fscanf_s(stream, "%d", &integerRead);
	return integerRead;
}


float StreamReadFloat(Stream stream)
{
	fscanf_s(stream, "%f", &floatRead);
	return floatRead;
}
void StreamReadVector2D(Stream stream, Vector2D* vector)
{
	
	vector->x = StreamReadFloat(stream);
	vector->y = StreamReadFloat(stream);
} 

void StreamClose(Stream* stream)
{
	if(stream != NULL)
	{
		fclose(*stream);
		*stream = NULL;
	}	
}