# Abstract

This project seeks to explore the field of depth estimation from monocular images.

It has been developed by Alvaro Rubio as part of the subject "Computer Vision and Multimedia Analysis" taught by Proff. Nicola Conci in the University of Trento, Italy.

# Introduction

To explore depth estimation from monocular images, a first research on te topic was made. From this first research it was conluded that the approach on the topic was twofold. 

On the one hand, we had the visual slam approach. Visual Simultaneous Localization And Mapping refers to the process of determining the position and orientation of a camera with respect to its surroundings, while simultaneously mapping the environment around that camera. Determining the position and orientation implies determining the depth of each point around the camera. There are many monocular SLAM systems (PTAM, MonoSLAM, SVO, DTAM, ORB-SLAM, etc) depending on the number of pixels used and the use of extracted features or pixel intesity.

On the other hand, we had deep learning approaches. In this field we found 



## Description of files
### YOLO
Yolo algorithm code.
Create folder inside called "weights" and add the weight file from the download section before running the algorithm.
source: https://github.com/Garima13a/YOLO-Object-Detection

### Monodepth2
Depth estimation algorithm from monocular images. Slightly modified from source to retrieve relative depth estimation (no scale applied)
source: https://github.com/nianticlabs/monodepth2

### preprocessing-code
Code for cropping the stereo images of the baseline in two monocular images. Preprocessed images can be find in "Left crop" in the download section.

### main.ipynb
Jupyter notebook. It includes the main code of this project. It is coded in an educational manner, i.e step by step, to facilitate the reuse or improvement of the code freely.

### contour-approach.ipynb
Jupyter notebook. It includes a different approach for solving our problem based on cropping the contour of the subject. It was discarded due to its unreliability.

## Download
[`YOLO weights`](https://mega.nz/#F!RUBB3YYJ!pbAz28PVzJnN4Vuq4KA5mg)

[`Baseline`](https://mega.nz/#F!9NQVkS7T!tasTrvKYt0w4h2sUOlsJJA) 

[`Left crop`](https://mega.nz/#F!tNBXRKKR!tDUTec3pCeqm5jBnJ5sDxg) 

[`monodepth2 output`](https://mega.nz/#F!kZQxRIKA!5pk7LA8qsHgg0moKPXFIgw) 

[`Results`](https://mega.nz/#F!FcZxwYyI!bRNRo3cnsVaOSvpLedlm2g) 

[`Test`](

