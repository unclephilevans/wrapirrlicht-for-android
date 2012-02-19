/*--------------------------------------------------*/
/*VirtualSociety System ServiceModuleTemplate Main File*/
/*CreateBy SRPLab                */
/*CreateDate: 2012-2-15  */
/*--------------------------------------------------*/
#include "SRPIrrlichtES2Engine_VSHeader.h"

/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*Function IrrDeviceClass Is Extracted From ScriptFile */
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define IRRDEVICECLASS_OBJECT_DEPENDINDEX                                                            0x00000001
#define IRRDEVICECLASS_GETCURDEVICE_FUNCRETURN_DEPENDINDEX                                           0X00000002
#define IRRDEVICECLASS_GETCURDEVICE_FUNCPARAM_DEPENDINDEX                                            0X00000003
#define IRRDEVICECLASS_LUA_GETCURDEVICE_FUNCRETURN_DEPENDINDEX                                       0X00000004
#define IRRDEVICECLASS_LUA_GETCURDEVICE_FUNCPARAM_DEPENDINDEX                                        0X00000005
#define IRRDEVICECLASS_RENDER_FUNCRETURN_DEPENDINDEX                                                 0X00000006
#define IRRDEVICECLASS_RENDER_FUNCPARAM_DEPENDINDEX                                                  0X00000007
#define IRRDEVICECLASS_LUA_RENDER_FUNCRETURN_DEPENDINDEX                                             0X00000008
#define IRRDEVICECLASS_LUA_RENDER_FUNCPARAM_DEPENDINDEX                                              0X00000009
#define IRRDEVICECLASS_SETSIZE_FUNCRETURN_DEPENDINDEX                                                0X0000000A
#define IRRDEVICECLASS_SETSIZE_FUNCPARAM_DEPENDINDEX                                                 0X0000000B
#define IRRDEVICECLASS_LUA_SETSIZE_FUNCRETURN_DEPENDINDEX                                            0X0000000C
#define IRRDEVICECLASS_LUA_SETSIZE_FUNCPARAM_DEPENDINDEX                                             0X0000000D
#define IRRDEVICECLASS_GETSCENEMANAGER_FUNCRETURN_DEPENDINDEX                                        0X0000000E
#define IRRDEVICECLASS_GETSCENEMANAGER_FUNCPARAM_DEPENDINDEX                                         0X0000000F
#define IRRDEVICECLASS_LUA_GETSCENEMANAGER_FUNCRETURN_DEPENDINDEX                                    0X00000010
#define IRRDEVICECLASS_LUA_GETSCENEMANAGER_FUNCPARAM_DEPENDINDEX                                     0X00000011
#define IRRDEVICECLASS_GETVIDEODRIVER_FUNCRETURN_DEPENDINDEX                                         0X00000012
#define IRRDEVICECLASS_GETVIDEODRIVER_FUNCPARAM_DEPENDINDEX                                          0X00000013
#define IRRDEVICECLASS_LUA_GETVIDEODRIVER_FUNCRETURN_DEPENDINDEX                                     0X00000014
#define IRRDEVICECLASS_LUA_GETVIDEODRIVER_FUNCPARAM_DEPENDINDEX                                      0X00000015
#define IRRDEVICECLASS_GETFILESYSTEM_FUNCRETURN_DEPENDINDEX                                          0X00000016
#define IRRDEVICECLASS_GETFILESYSTEM_FUNCPARAM_DEPENDINDEX                                           0X00000017
#define IRRDEVICECLASS_LUA_GETFILESYSTEM_FUNCRETURN_DEPENDINDEX                                      0X00000018
#define IRRDEVICECLASS_LUA_GETFILESYSTEM_FUNCPARAM_DEPENDINDEX                                       0X00000019

VS_INT32 SRPCALLBACK IrrDeviceClass_QueryObjectInfo(VS_OBJECTMODULEINFO *VSObjectModuleInfo)
{
    VSObjectModuleInfo -> ObjectVersion = 0;
    VSObjectModuleInfo -> ObjectSubVersion = 0;
    VSObjectModuleInfo -> ObjcetBugFixVersion = 0;
    VSObjectModuleInfo -> VSVersion = 0;
    VSObjectModuleInfo -> VSSubVersion = 0;

    VSObjectModuleInfo -> CreateTime.wYear = 2012;
    VSObjectModuleInfo -> CreateTime.wMonth = 2;
    VSObjectModuleInfo -> CreateTime.wDay = 15;
    VSObjectModuleInfo -> UpdateTime.wYear = 2012;
    VSObjectModuleInfo -> UpdateTime.wMonth = 2;
    VSObjectModuleInfo -> UpdateTime.wDay = 15;

    strcpy( VSObjectModuleInfo -> AuthorityInfo, "" );
    strcpy( VSObjectModuleInfo -> LicenseInfo, "" );
    strcpy( VSObjectModuleInfo -> ExtendInfo, "" );

    return 0;
}

VS_INT32 SRPCALLBACK IrrDeviceClass_RequestRegisterObject()
{
    VS_DEPENDATTRIBUTE LocalDependAttribute[512];  /*---set a large number*/
    VS_INT32 DependIndexNumber,DependIndex[64];

    //------register object depend
    VSATTRDEPEND_IRRDEVICECLASS(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_OBJECT_DEPENDINDEX,VSOBJID_IrrDeviceClass,VSMODULEDEPEND_OBJECT,VSATTRDEPENDNUM_IRRDEVICECLASS,LocalDependAttribute);

    //------register function depend
    VSFUNCRETURNDEPEND_IRRDEVICECLASS_GETCURDEVICE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_GETCURDEVICE_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrDeviceClass_GetCurDevice,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_GETCURDEVICE,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRDEVICECLASS_GETCURDEVICE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_GETCURDEVICE_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrDeviceClass_GetCurDevice,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_GETCURDEVICE,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRDEVICECLASS_LUA_GETCURDEVICE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_LUA_GETCURDEVICE_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrDeviceClass_Lua_GetCurDevice,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_LUA_GETCURDEVICE,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRDEVICECLASS_LUA_GETCURDEVICE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_LUA_GETCURDEVICE_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrDeviceClass_Lua_GetCurDevice,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_LUA_GETCURDEVICE,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRDEVICECLASS_RENDER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_RENDER_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrDeviceClass_Render,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_RENDER,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRDEVICECLASS_RENDER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_RENDER_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrDeviceClass_Render,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_RENDER,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRDEVICECLASS_LUA_RENDER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_LUA_RENDER_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrDeviceClass_Lua_Render,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_LUA_RENDER,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRDEVICECLASS_LUA_RENDER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_LUA_RENDER_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrDeviceClass_Lua_Render,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_LUA_RENDER,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRDEVICECLASS_SETSIZE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_SETSIZE_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrDeviceClass_SetSize,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_SETSIZE,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRDEVICECLASS_SETSIZE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_SETSIZE_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrDeviceClass_SetSize,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_SETSIZE,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRDEVICECLASS_LUA_SETSIZE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_LUA_SETSIZE_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrDeviceClass_Lua_SetSize,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_LUA_SETSIZE,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRDEVICECLASS_LUA_SETSIZE(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_LUA_SETSIZE_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrDeviceClass_Lua_SetSize,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_LUA_SETSIZE,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRDEVICECLASS_GETSCENEMANAGER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_GETSCENEMANAGER_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrDeviceClass_GetSceneManager,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_GETSCENEMANAGER,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRDEVICECLASS_GETSCENEMANAGER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_GETSCENEMANAGER_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrDeviceClass_GetSceneManager,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_GETSCENEMANAGER,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRDEVICECLASS_LUA_GETSCENEMANAGER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_LUA_GETSCENEMANAGER_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrDeviceClass_Lua_GetSceneManager,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_LUA_GETSCENEMANAGER,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRDEVICECLASS_LUA_GETSCENEMANAGER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_LUA_GETSCENEMANAGER_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrDeviceClass_Lua_GetSceneManager,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_LUA_GETSCENEMANAGER,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRDEVICECLASS_GETVIDEODRIVER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_GETVIDEODRIVER_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrDeviceClass_GetVideoDriver,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_GETVIDEODRIVER,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRDEVICECLASS_GETVIDEODRIVER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_GETVIDEODRIVER_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrDeviceClass_GetVideoDriver,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_GETVIDEODRIVER,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRDEVICECLASS_LUA_GETVIDEODRIVER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_LUA_GETVIDEODRIVER_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrDeviceClass_Lua_GetVideoDriver,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_LUA_GETVIDEODRIVER,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRDEVICECLASS_LUA_GETVIDEODRIVER(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_LUA_GETVIDEODRIVER_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrDeviceClass_Lua_GetVideoDriver,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_LUA_GETVIDEODRIVER,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRDEVICECLASS_GETFILESYSTEM(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_GETFILESYSTEM_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrDeviceClass_GetFileSystem,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_GETFILESYSTEM,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRDEVICECLASS_GETFILESYSTEM(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_GETFILESYSTEM_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrDeviceClass_GetFileSystem,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_GETFILESYSTEM,LocalDependAttribute);

    VSFUNCRETURNDEPEND_IRRDEVICECLASS_LUA_GETFILESYSTEM(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_LUA_GETFILESYSTEM_FUNCRETURN_DEPENDINDEX,VSFUNCID_IrrDeviceClass_Lua_GetFileSystem,VSMODULEDEPEND_FUNCRETURN,VSFUNCRETURNDEPENDNUM_IRRDEVICECLASS_LUA_GETFILESYSTEM,LocalDependAttribute);

    VSFUNCPARAMDEPEND_IRRDEVICECLASS_LUA_GETFILESYSTEM(LocalDependAttribute);
    pSRP -> RegisterObjectDependency( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,IRRDEVICECLASS_LUA_GETFILESYSTEM_FUNCPARAM_DEPENDINDEX,VSFUNCID_IrrDeviceClass_Lua_GetFileSystem,VSMODULEDEPEND_FUNCPARA,VSFUNCPARAMDEPENDNUM_IRRDEVICECLASS_LUA_GETFILESYSTEM,LocalDependAttribute);

    //------object function
    DependIndexNumber = 3;
    DependIndex[0] = IRRDEVICECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRDEVICECLASS_GETCURDEVICE_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRDEVICECLASS_GETCURDEVICE_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,VSFUNCID_IrrDeviceClass_GetCurDevice,(void *)IrrDeviceClass_GetCurDevice,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRDEVICECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRDEVICECLASS_LUA_GETCURDEVICE_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRDEVICECLASS_LUA_GETCURDEVICE_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,VSFUNCID_IrrDeviceClass_Lua_GetCurDevice,(void *)IrrDeviceClass_Lua_GetCurDevice,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRDEVICECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRDEVICECLASS_RENDER_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRDEVICECLASS_RENDER_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,VSFUNCID_IrrDeviceClass_Render,(void *)IrrDeviceClass_Render,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRDEVICECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRDEVICECLASS_LUA_RENDER_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRDEVICECLASS_LUA_RENDER_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,VSFUNCID_IrrDeviceClass_Lua_Render,(void *)IrrDeviceClass_Lua_Render,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRDEVICECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRDEVICECLASS_SETSIZE_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRDEVICECLASS_SETSIZE_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,VSFUNCID_IrrDeviceClass_SetSize,(void *)IrrDeviceClass_SetSize,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRDEVICECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRDEVICECLASS_LUA_SETSIZE_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRDEVICECLASS_LUA_SETSIZE_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,VSFUNCID_IrrDeviceClass_Lua_SetSize,(void *)IrrDeviceClass_Lua_SetSize,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRDEVICECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRDEVICECLASS_GETSCENEMANAGER_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRDEVICECLASS_GETSCENEMANAGER_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,VSFUNCID_IrrDeviceClass_GetSceneManager,(void *)IrrDeviceClass_GetSceneManager,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRDEVICECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRDEVICECLASS_LUA_GETSCENEMANAGER_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRDEVICECLASS_LUA_GETSCENEMANAGER_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,VSFUNCID_IrrDeviceClass_Lua_GetSceneManager,(void *)IrrDeviceClass_Lua_GetSceneManager,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRDEVICECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRDEVICECLASS_GETVIDEODRIVER_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRDEVICECLASS_GETVIDEODRIVER_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,VSFUNCID_IrrDeviceClass_GetVideoDriver,(void *)IrrDeviceClass_GetVideoDriver,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRDEVICECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRDEVICECLASS_LUA_GETVIDEODRIVER_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRDEVICECLASS_LUA_GETVIDEODRIVER_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,VSFUNCID_IrrDeviceClass_Lua_GetVideoDriver,(void *)IrrDeviceClass_Lua_GetVideoDriver,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRDEVICECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRDEVICECLASS_GETFILESYSTEM_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRDEVICECLASS_GETFILESYSTEM_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,VSFUNCID_IrrDeviceClass_GetFileSystem,(void *)IrrDeviceClass_GetFileSystem,DependIndexNumber,DependIndex);

    DependIndexNumber = 3;
    DependIndex[0] = IRRDEVICECLASS_OBJECT_DEPENDINDEX;
    DependIndex[1] = IRRDEVICECLASS_LUA_GETFILESYSTEM_FUNCRETURN_DEPENDINDEX;
    DependIndex[2] = IRRDEVICECLASS_LUA_GETFILESYSTEM_FUNCPARAM_DEPENDINDEX;
    pSRP -> RegisterObjectFunction( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,VSFUNCID_IrrDeviceClass_Lua_GetFileSystem,(void *)IrrDeviceClass_Lua_GetFileSystem,DependIndexNumber,DependIndex);

    //------object sysevent process
    DependIndexNumber = 1;
    DependIndex[0] = IRRDEVICECLASS_OBJECT_DEPENDINDEX;
    pSRP -> RegisterObjectSysEvent( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,(void *)IrrDeviceClass_OnSystemEvent,DependIndexNumber,DependIndex);

    //------object message process
    pSRP -> RegisterQueryObjectInfo( VSIMPORTMODULEID_SRPIrrlichtES2EngineBasicModule,VSOBJID_IrrDeviceClass,(void *)IrrDeviceClass_QueryObjectInfo);

    return 0;
}

