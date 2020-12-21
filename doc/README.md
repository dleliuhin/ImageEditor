# Task

I am looking to develop a C++/Qt/openCV based simple image editor for a client.
It is planned to be used only in the Windows OS.
(Source code is the deliverable)


 1. <s>We should be able to open any image (bmp/png/jpg/jpeg)</s>

 2. <s>We should be able to zoom into any rectangular subregion of the image. The plan is to open the zoomed area in a new window. As long as it is done serially one after the other; we should be able to zoom into multiple subregions and make edits.</s>

 3. <s>In this zoomed subregion; we should be able to draw and fill polygons with any color (Although only polygons are required as of now; lines could be required in the future - so we need to make plans for that).</s>

 4. <s>New subregions should be in a single MultiTabView of subwindow. This is because if there are overlapping subwindows , it creates some confusion regarding which overlapping polygon will have precedence/priority.</s>

 5. The polygon to be filled only after all the vertices have been decided. Each point can be merged    through the region. Each point must have own olygon ID number started from 1.

 6. Choose colors in 3 possible ways:

    -- Manual coloring

    	R,G,B,A - slider bars(0-255) for R,G,B resulting in a single color preview

        It would be ideal if the slider bars have random access

       based on the location where we select on the slider bar (0-255).

    -- palette file -

       this is a text file with tuples

         color_alias , r , g , b , a

        listed one below the other

    	palette.txt

       dark_red , 255 , 0 , 0 , 200
       light_red  ,  170 , 0 ,0 , 240

       my_favorite_green , 0 , 240 , 20  , 190
           # red_not_used , 100 , 0 , 0 , 44

         We should be able to load the text file aliases into a drop down list .

       When an item is selected from the drop down list ;  we should be 
        able to preview the color and the numbers

       In the palette file , empty lines should be ignored
       If the first non-space character is a '#' ; those lines should also be ignored

    -- color borrow mode - colors are averaged from a chosen rectangle

     These 3 coloring methods can be initialized to default values
     and can be modified by the user

     Before doing fillpoly , we should somehow ask the user which of the above 3 methods
     is used for deciding the color and alpha


    -- We should be able to preview the whole image before saving.

    -- Output will have the same format and size as input

```
   bmp -> bmp
   png -> png
   jpg -> jpg
   jpeg -> jpeg
```

    -- By default the input image will be overwritten, unless the user decides to change the output path.

    -- Looking for a clean , intuitive and modern user interface.

```
   g1 - Include a splash screen at startup (private - Qt resources)
   g2 - Left pane Logo1 -  app_logo - (private - Qt resources)
   g3 - Left pane Logo2  -  customer_logo   -   (public - hard_disk)
```

 7 . Use the mouse right button to draw rectangle for borrowing color.

 8 . Help menu - >  Credits Submenu

    Credits to the following libraries :
    Qt -> links to Qt webpage when clicked
    OpenCV -> links to OpenCV webpage when clicked

-----------------------------------------------------------------------------

9 . Color selection architecture.

--  R, G, B and A   are represented by slider bars with random access

    R = Red
    G = Green
    B = Blue
    A = Alpha

-- Initially default values of R,G,B and A are selected
   These values can be adjusted manually (manual mode)


-- When a color is selected by mouse right rectangle averaging (borrow mode), the values R,G,B in the          slider bars are updated


-- When a color_alias is selected from the palette file (palette mode); R,G,B,A are updated in the slider bars


--  At all points of time; the RGBA color value represented by the slider bars is previewed.
    R,G,B is previewed both numercially as well as small square box with the color.
    A is previewed only numerically.

-----------------------------------------------------------------------------

R,G,B for filling polygons can be input in 3 ways
Each polygon will have different R,G,B,alpha


1) Manual - R,G,B,alpha

2) Select one entry from palette txt file which has a list of tuples
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







