// this is made by beyond
// update 1997.6.20

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"�ӻ���"NOR);
        set("long", @LONG
��������٢��ɽׯ���ӻ��ң���������˸��ֲ��õľ���Ʒ�����ӻ���
��һ�ǰڷ���һ�������ܡ�
LONG    );
        set("exits", ([ 
                "west" : __DIR__"hhyuan",
                "east" : __DIR__"cl4-5",
        ]));
        set("objects",([
//                        __DIR__"obj/jia" : 1,
   		]));
        setup();

}


