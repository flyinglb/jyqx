//LUCAS 2000-6-18
// Room: sroad4.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","��紨");
        set("long",@LONG
����վ��һ�龧Ө��͸���������֮�ϣ�ֻ���Ų����ϴ���
һ��͸�ǵı�����ѩɽ�ϱ���ŭ�ţ�������Ƶ�������ѩ����
��һƬ��ã���Ѿ�������������������ˡ�ƬƬѩ���ӿ��ж�ë
��������¡�����ﻬ����·������춱��ϡ���ν��ѩ���ѣ���
�������족��
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "southdown"  : __DIR__"shiya",
            "northup"  : __DIR__"sroad5",
        ]));
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "northup" || dir == "southdown") {
                me->add("jing", -30);
                me->add("qi", -30);
        }
        return 1;
}       
