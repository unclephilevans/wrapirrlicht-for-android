# Wrapping Irrlicht for Android #

Irrlicht is well-known open source 3D engine, which supports multiple platforms. It has been ported to android by Laurent Mallet, source code can be obtained from https://gitorious.org/irrlichtandroid/. The code is written in c++ language, but android mainly supports the java language. Using native c++ on android to develop applications is more difficult, and not convenient, especially to debug. For developer to use irrlicht easily, it is best to provide java interfaces.

The work here is wrapping irrlicht engine to enable it to provide the java interface. Traditional method for java calling native code is using the jni mechanism. But irrlicht engine is big and has many render objects. Using jni directly to wrap irrlicht will be a hard work. We have to define classes in java, create c++ code skeleton, maintain global reference of java object to irrlicht render object, process callback, etc. In order to simplify programming, CLE is used as middleware to help java to call native code.

The wrapping engine supports opengl es2.0, and can works on platform both for windows and android.

## The project is in progress, welcome to join, source code can be obtained from http://code.google.com/p/warpirrlicht-for-android/source/checkout ##

# Using warpirrlicht : First Method #

copy share libraries of cle into libs/armeabi directory of your project, and copy SRPFSEngine.xml and SRPIrrlichtES2Engine.xml into assets directory. As follows:

http://www.srplab.com/Images/android/warpirrlicht_libs.JPG

and using following code to init cle and irrlicht

```
    import com.srplab.www.starcore.*;

    starcore= StarCoreFactory.GetFactory();	
    SrvGroup = starcore._GetSrvGroup(0);
    try{
       	String xmlbuf;
        	
       	InputStream dataSource = assetManager.open("SRPFSEngine.xml");
       	int size=dataSource.available();
       	byte[] buffer=new byte[size]; 
       	dataSource.read(buffer); 
       	dataSource.close();        
       	xmlbuf=new String(buffer);
       	SrvGroup._ImportServiceFromXmlBuf(xmlbuf, true);
	       	
       	dataSource = assetManager.open("SRPIrrlichtES2Engine.xml");
       	size=dataSource.available();
       	buffer=new byte[size]; 
       	dataSource.read(buffer); 
       	dataSource.close();        
       	xmlbuf=new String(buffer);
       	SrvGroup._ImportServiceFromXmlBuf(xmlbuf, true);	       	
    }
    catch(IOException e ){
    }   
    SrvGroup._CreateService( "","test", "123",5,0,0,0,0,0,"" );
    Service = SrvGroup._GetService("root","123");

    ...
```

# Using warpirrlicht : Second Method #

Download share libraries of cle from network dynamically. Using this method, install package will be smaller. As follows:

```
    import com.srplab.www.starcore.*;
    import com.srplab.netinst.*;
        starcore_net_inst.InstallZipFile(this,"libstarcore.so","http://www.srplab.com/android/starcore_armeabi_r3.zip", "/data/data/com.srpirrlicht.helloworld_netinst/files");
        starcore_net_inst.InstallZipFile(this,"SRPIrrlichtES2Engine/SRPIrrlichtES2EngineBasicModule_android.so","http://www.srplab.com/android/SRPIrrlichtES2Engine.zip", "/data/data/com.srpirrlicht.helloworld_netinst/files");
        StarCoreFactoryPath.StarCoreShareLibraryPath = "/data/data/com.srpirrlicht.helloworld_netinst/files";
        StarCoreFactoryPath.StarCoreOperationPath = "/data/data/com.srpirrlicht.helloworld_netinst/files";

    starcore= StarCoreFactory.GetFactory();
    Service = starcore._InitSimple("RemoteCallServer", "123",0,0,StarCoreFactoryPath.StarCoreShareLibraryPath+"/SRPFSEngine",StarCoreFactoryPath.StarCoreShareLibraryPath+"/SRPIrrlichtES2Engine" );
    ...
```

starcore\_netinst\_r3.jar can be downloaded from http://code.google.com/p/cle-for-android


# Examples #

http://www.srplab.com/Images/android/warpirrlicht_HelloWorld.JPG

## package can be download from download page ##

full examples code can be got from download page

```
    //--your code begin here
    StarObjectClass VDiskDrive;
    StarObjectClass SceneManager,VideoDriver;
    StarObjectClass Texture1,Node,Cam;
		
    private void InitGame() {
	VDiskDrive = Service._GetObject("DriveClass")._New("VDisk")._Assign(new StarObjectClass(){
        public Object[] OnRead(StarObjectClass self,Hashtable Ev,String FileName,Object BinBuf){
            byte[] buffer = new byte[1024];                
            try{
                InputStream dataSource = assetManager.open(FileName);
                int readLen = 0;  
    	        while((readLen = dataSource.read(buffer)) != -1){  
    	           ((StarBinBufClass)BinBuf)._Write(((StarBinBufClass)BinBuf)._Getint("_Offset"),buffer,readLen);
    	            }           
            }
            catch(IOException e ){
            }             	            
            return null;
        }
    });		
    VDiskDrive._Call("Lua_LoadWebFile","sydney.bmp","sydney.bmp","","","");
    VDiskDrive._Call("Lua_LoadWebFile","sydney.md2","sydney.md2","","","");
                
    SceneManager = (StarObjectClass)Device._Call("Lua_GetSceneManager");
    VideoDriver = (StarObjectClass)Device._Call("Lua_GetVideoDriver");

    Texture1 = Service._GetObject("IrrTextureClass")._New();
    Texture1._Set("TextureFile","VDisk:\\sydney.bmp");
    Texture1._Active(); 
    
    Node = Service._GetObject("IrrAnimatedMeshSceneNodeClass")._New(SceneManager);
    Node._Set("MeshFile","VDisk:\\sydney.md2");
    Node._Set("MD2AnimationType",Service._Get("IRREMAT_STAND"));
    Node._Active();
    Node._Call("Lua_SetMaterialFlag",Service._Get("IRREMF_LIGHTING"), false);
    Node._Call("Lua_SetMaterialTexture", 0, Texture1 );
    
    Cam = Service._GetObject("IrrCameraSceneNodeClass")._New(SceneManager);
    Cam._Set("Position",new Object[]{0,30,-40});
    Cam._Set("Target",new Object[]{0,15,0});
    Cam._Active();
}
```