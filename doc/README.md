# Task

I am looking to develop a C++/Qt/openCV based simple image editor for a client.
It is planned to be used only in the Windows OS.
(Source code is the deliverable)


 1. We should be able to open any image (bmp/png/jpg/jpeg)

 2. We should be able to zoom into any rectangular subregion of the image. The plan is to open the zoomed area in a new    window. As long as it is done serially one after the other; we should be able to zoom into multiple subregions and make edits.

3. In this zoomed subregion; we should be able to draw and fill polygons with any color (Although only polygons are required as of now; lines could be required in the future - so we need to make plans for that).

- We should be able to preview the whole image before saving.

- Output will have the same format and size as input
```
   bmp -> bmp
   png -> png
   jpg -> jpg
   jpeg -> jpeg
```

- By default the input image will be overwritten, unless the user decides to change the output path.

- Looking for a clean , intuitive and modern user interface.
```
   g1 - Include a splash screen at startup (private - Qt resources)
   g2 - Left pane Logo1 -  app_logo - (private - Qt resources) 
   g3 - Left pane Logo2  -  customer_logo   -   (public - hard_disk)
```

h)  Help menu - >  Credits Submenu

    Credits to the following libraries :
    Qt -> links to Qt webpage when clicked
    OpenCV -> links to OpenCV webpage when clicked

 
-----------------------------------------------------------------------------

R,G,B for filling polygons can be input in 3 ways
Each polygon will have different R,G,B,alpha


1) manual - R,G,B,alpha

2) select one entry from palette txt file which has a list of tuples
   color_alias , R , G , B , alpha

  (In the palette file ; empty lines should be ignored; 

   Also lines whose first non-space character is '#' should be ignored)
   

3) be able to "borrow" a R,G,B from a different rectangular patch in the zoomed image
    (average of all the R,G,B in the region)

   alpha(0-255) needs to be manually provided - defaults to 255

----------------------------------------------------------------------------

My experience in opencv is quite basic; so the following functions
may be useful or maybe not.

cv::FillPoly() could be used for filling polygons
cv::AddWeighted() could be used for alpha blending

-----------------------------------------------------------------------------

Payment is on an hourly basis.

The freelancer will keep track of his time using the time tracker tool on the website.
Also , the freelancer will upload the code to a shared repository after each milestone.

IP agreement is required.
If you do a similar app for another client; it needs to have a different
look and feel experience.
Also, you will not advertize this work on your portfolio.

-----------------------------------------------------------------------------







