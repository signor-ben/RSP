/*
design a video stream system, with a consideration on security
- more about surveillance
- local application with cloud storage
- primary user would be hotel security
- currently think about only one camera, but consider scalability
-  



classes:
Camera
- method to send a stream of data 
- variable data - private/protected
-  
 
Storage
- handles storage 
- handles uploading data
- handles last 8 hours of backup on physical/local storage


Monitor
- can take in data from multiple cameras
- method display
- functionality for the end user


*/

int globalCamID;
int globalMonID;

class Camera
{
    private:
        Video data;
        int ID;

    public:
        void sendData();
        void storeData(Storage store);

};

class Storage
{
    public:
        void uploadData(webservice) // upload to a webservice
        {
            while(webervice)
            {
                try 
                    StorageService.upload() // storageService is external API handler class for Cloud storage
                catch
                    backupData();

            }
        }
        void writeData(); //  this would write the past 8 hours of video
        void backupData(); // is called when the webservice in compromised

};

class Monitor
{
    private:
        int ID;
        vector<Camera*> linkedCameras; // store camera that are linked the current monitor

    public:
        void displayFeed(camerafeed);
        void addCamera(Camera cam); // add the camera object to the linkedCameras
        void removeCamera(Camera cam);

};


// 4 cameras, and 2 monitors
// 2 securituy guard, one at monitor a looking at 3 camera feeds, 1 at monitor b looking at 1


















