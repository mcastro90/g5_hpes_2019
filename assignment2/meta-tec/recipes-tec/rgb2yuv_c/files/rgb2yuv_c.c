#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;
#define clamp(val)  ((val)> 255 ? 255 : (val) < 0 ? 0 : val )

     
void main()
{
          int size = 0;
          char * buffer = NULL;
          char * buffer2 = NULL;
          FILE *image_raw = fopen("raw_test.raw", "rb");

          if (image_raw)
            {
          fseek(image_raw,0,SEEK_END);
          size=ftell(image_raw);
          fseek (image_raw,0,SEEK_SET);
          buffer = malloc (size);
          if(size!=-1)
              printf("File size is: %ld\n",size);
          else
              printf("There is some ERROR.\n");
            }
           typedef unsigned char byte;

           int *rgb = (int*)calloc((640*480*3), sizeof(int));
           int *ptr = rgb;
          if (buffer)
          {
            fread(buffer,size,sizeof(char),image_raw);
            fclose(image_raw);
            int index = 0;
           int y;
           for(y = 0; y < 480; ++y)
           {

               for(index = 0; index < 640; ++index, buffer+= 3)
                {
                 const byte r = buffer[0];
                 const byte g = buffer[1];
                 const byte b = buffer[2];
		       
                 unsigned int Y;
                 unsigned int U;
                 unsigned int V;
                 Y = clamp(0.257 *  r + 0.504 * g + 0.098 * b +16);
                 U = clamp(0.439 *  r + 0.368 * g - 0.071 * b + 129);
                 V = clamp(-0.148 * r - 0.291 * g + 0.439 * b + 128);
                 //printf("Y%2d U%2d V%2d  " , Y, U , V);
                 *ptr++ = clamp(Y);
                 *ptr++ = clamp(U);
                 *ptr++ = clamp(V);
                }
            FILE * yuv_file;
           yuv_file = fopen("yuv_file.yuv", "w");
           fwrite(rgb, sizeof(char), sizeof(rgb), yuv_file);
           fclose(yuv_file);
             }
         }
      }
