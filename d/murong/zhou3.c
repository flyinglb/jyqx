// /u/beyond/mr/zhou3.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "С��");
	set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ����ʮ������������ֳֳ���
�ݣ����ڴ�β�����س��Ŵ���
LONG
	);
	set("exits",([
		"out"  :  __DIR__"anbian2",
	]));
        set("no_fight",1);

	setup();
}
void init()
{
//  mapping fam;
    object me;
       me=this_player();
//     room=this_object();
       message_vision(
               YEL "\n�����С�ۿ��ڰ��ߣ����´��ɡ�\n\n"NOR,me);
}

