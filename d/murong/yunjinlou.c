// /u/beyond/mr/yunjinlou.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",MAG"�ƽ�¥"NOR);
         set("long",@long
�ƽ�¥���踻��, һ�����û���ǿ�ȸ����,����������д��һ������
(duilian)��������һ��������������᷿�����������Ǻ�Ժ�������Ǻ�԰��
long);
         set("item_desc", ([
             "duilian" : "��Ҷ�Ʋ���, �軨ѩ���ޡ�\n"
]));
set("valid_startroom", 1);
set("exits",([
"east" : __DIR__"keting",
"west" : __DIR__"xiangfang1",
"south" : __DIR__"hhyuan",
"up" : __DIR__"cangshuge",
"north" : __DIR__"houyuan",
]));
set("objects",([
__DIR__"npc/wang" : 1,
]));
	setup();
//	replace_program(ROOM);
}
  
int valid_leave(object me, string dir)
{
        mapping fam;
        fam = (mapping)me->query("family");

        if ((!fam || fam["family_name"] != "����Ľ��") && dir == "up" &&
                objectp(present("wang furen", environment(me))))
                return notify_fail("¥��������٢��ɽׯ�Ĳ�����㲻��Ľ�ݵ��ӣ����ǲ�Ҫ��ȥ�˰ɣ�\n");

                  return ::valid_leave(me, dir);
} 

