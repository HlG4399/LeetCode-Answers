using UnityEngine;
using System.Collections;

public class C_16_3_2_Server : MonoBehaviour
{
    string gameName = "CrazyBalls";

    void Start()
    {
        //初始化服务器
        Network.InitializeServer(32, 25003, false);
        //在MasterServer上注册本服务器，命名为“小苹果的房间”，介绍为“来一起玩吧
        MasterServer.RegisterHost(gameName, "小苹果的房间", "来一起玩吧");
    }
}
