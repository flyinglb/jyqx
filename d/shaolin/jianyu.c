// Room: /d/shaolin/jianyu.c
// Date: YZC 96/02/06

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ڳ����ģ�����һ˿������Ҳ�ް����Ϣ���ڰ�����ϡ
���Կ�������ƺ��м�����Ӱ��������ת��ͷȥ������������ס
���������ŵص����㡣�ı�����ȥ�������Ҽ�Ӳ���ƺ����Ǹ���
���ɣ�ֻ���ϱ������һ��С�ţ����Ͽ��˸����ƴ�Ķ�������
�ͷ��õġ��ű���һ�Ѷ�������ȥ�����ݵ�ɢ�˿�����ϸ��ȴ��
һ�߰׵÷����Ŀݹǡ�
LONG );
	set("exits", ([
		"south" : __DIR__"jianyu1",
	]));
	set("valid_startroom",1);
	set("objects",([
		CLASS_D("shaolin") + "/qing-yuan" : 1,
		"d/shaolin/obj/fojing1"+random(2) : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}

void init()
{       
	object ob = this_player();

	if( (int)ob->query_condition("bonze_jail") <= 0 )
	{
		message("vision",
			HIY "ֻ���η����ſ��һ�죬һ���������ļһﱻ���˽�����\n\n" NOR, 
			environment(ob), ob);

		tell_object(ob, "����ٺٵ�Ц�ţ���������������������...��\n");

		ob->set("startroom", "/d/shaolin/jianyu");
		ob->apply_condition("bonze_jail", 60);
	}
}

