// /u/beyond/mr/zhuangmen.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",GRN"ׯ��"NOR);
        set("long",
"��ת��һ��ï�ܵĻ���, ��Ȼ��, ֻ��һ����������, С�������ׯԺ��\n"
"���ڲ����Ļ����С�ׯ�Ŵ����Ϻ�Ȼд�š�"HIY"������ɽׯ"NOR"�������������Ĵ��֡�\n"
);
       set("outdoors","mr");
       set("exits",([
           "west" : __DIR__"hc",
"east" : __DIR__"qianyuan",
"south" : __DIR__"xiaojing1-0",
           "north" : __DIR__"hc1",
]));
        setup();
}

