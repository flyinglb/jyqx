// Room: /d/huashan/yuntai.c
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��̨��");
        set("long", @LONG
̫������������̨�壬����������������һ����᫵ĳ��룬����
��һ����׵���ƵĵǷ����ݡ���¯������ŷ幰�����ң����أͻ����
̨���涼�����¾��ڣ�ʮ���վ����嶥�������乬������ͨ��������ʯ
��¥���������⡰���嶥�����֡�
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "southdown" : __DIR__"canglong",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "huashan");
        setup();
}
 
void init()
{
        object me = this_player();
        if (me->query_temp("xunshan")) me->set_temp("xunshan/yuntai", 1);
        return;
}
