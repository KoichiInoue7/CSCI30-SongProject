This is the project that we are currently working on in class, so every time we learn something new, we implement it here. The goal of the project is to create a 
playlist of songs and podcasts, but by properly handling memory with destructors and smart pointers, and using exceptions. This project was built with OOP in mind, 
creating the base class AudioStream and the subclasses Song and Podcast to inherit from. Other classes, such as Playlist, were used to obtain the data of audioStream 
and store it in an array of shared_ptrs. These smart pointers allowed us to keep manage RAII by deleting upon going out of scope automatically and keeping the 
construction within that smart pointer class. I added exceptions around functions like get() so that if the user wanted to get unaccessible data, an exception would be
thrown and caught outside the function call while still calling the destructor. I removed raw pointers because the uncertainty about who is responsible for their 
deletion may lead to problems with stack unwinding and exceptions skipping over the destructor. With this in mind, I want to grow in complexity to handle new projects
independently. Throughout this project, it’s been easy to implement things such as smart pointers because I’ve been told to do so. I want to bring out my creative side
and create projects that require problem-solving for myself, such as adding search features to filter this playlist.

