// /u/beyond/mr/xiaozhou3.c
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�ɴ�");
	set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ���������ֳֳ���ݣ����ڴ�
β�����س��Ŵ���
LONG
	);
	set("exits",([
		"out"  :  __DIR__"anbian",
	]));
        set("no_fight",1);
	setup();
}
void init()
{
       mapping fam;
       object me,room;
       me=this_player();
       room=this_object();
       message_vision(
               YEL "\n���ڵ��˰��ߣ������С�ۿ��ڰ��ߣ����´��ɡ�\n\n"NOR,me);
}




