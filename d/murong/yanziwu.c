// /u/beyond/mr/yanziwu.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",WHT"������"NOR);
         set ("long",@long
��������Ļ��������֮��, Ļ������Ϧ�մ�����ĺ���, �����ռ�ʽ΢, 
�������ȴһ��һ����⸴���ࡣ���书�������Ա�֮��, ��ʩ����, �˵�
ʮ��������
long);
         set("exits",([
"south" : __DIR__"xiaojing1-2",
"west" : __DIR__"houyuan1",
             "east" : __DIR__"wuchang",
]));
set("objects",([
	__DIR__"npc/murong-fu" :1,
//        "/d/biwu/champion_mr":1,
]));
        "/clone/board/murong_b.c"->foo();
         setup();
         replace_program(ROOM);
}

