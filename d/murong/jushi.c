// /u/beyond/mr/jushi.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"����"NOR);
         set ("long",@long
���Ǵ��ƽʱ������ӵĵط�, �������һ�߹���, һ������, �����
����۸���, ���˰�˼������⡣���ҵĶ����Ǵ�����������һ�����ȣ���
����һ���᷿��
long);                                                           
         set("item_desc",([
         "qiju" : "һ��ɱ���ѽ��ѷ׵��壬��֪���Ƿ����о�һ�£�\n",
         ]));
         set("exits",([
             "east" : __DIR__"dating",
             "west" : __DIR__"cl6-0",
             "south" : __DIR__"xiangfang3",
]));

	setup();
}



int do_yanjiu(string arg)
{
	object me;

	me = this_player();
        if ( !living(this_player()) || arg != "qiju" )
                 return 0;
	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
         if ( (int)me->query("jing")<30) {
 me->receive_damage("jing", 10);
                 write("��̫���ˣ��Ѿ�û���������ж�����ˣ�\n");  
                 return 1;
}
me->receive_damage("jing", 10);

	message_vision("$N��ר���о����ϵġ���֡���\n", me);

	if ( (int)me->query_skill("parry", 1) < 31)
	{
		me->improve_skill("parry", me->query("int"));
		write("����������ϵġ���֡���ĥ��һ�ض����ƺ��Ի����м������ĵá�\n");
		return 1;
	}

	write("���������о���һ�ᣬ�������Ѿ��о�͸����������˵�Ѻ��������ˡ�\n");

	return 1;
}



