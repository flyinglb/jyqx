// /u/beyond/mr/muqiao.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",YEL"ľ��"NOR);
         set ("long",@long
����ͨ������Сͤ��ľ�ţ�������ȥ����̲���������ɫ���ˡ�ľ�ŵ�
�����ϵ����һ����Сľͷʨ�ӣ����˰������֡�ľ�����������ܹ�����һ
������Сͤ��
long);
         set("outdoors","mr");
         set("exits",([
             "east" : __DIR__"houyuan1",
             "west" : __DIR__"bishuiting",
]));
         setup();
         replace_program(ROOM);
}

