//Robin 2000.5.9
//Last Modify: Byp@MX 2001.06.09

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɽ����");
	set("long", @LONG
�����ǽ���Ѿ��ವ��Ψ�������е�ɽ�����������ûʲô���𣬾�˵
����ǧ����������ɽ��������һ��ɽ����Ȼ�����й����ɽ����ʲô����
�����Ѿ�û����˵�����ˡ�
LONG );
	set("exits", ([
		"west" : __DIR__"houshan2",
	]));
	set("item_desc", ([
		"shanshen" : "���ɽ���е�Ź֣������Ȼ���ű��������Ը�����ͷ(ketou)����ô����\n",
		"ɽ��" : "���ɽ���е�Ź֣������Ȼ���ű��������Ը�����ͷ(ketou)����ô����\n",
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_ketou","ketou");
}
int do_ketou(object me)
{
	int skl1;
	int skl2;
	int skl3;
	int skl4;
	me = this_player();
	skl1 = (int)me->query_skill("chess",1);
	skl2 = (int)me->query_skill("music",1);
	skl3 = (int)me->query_skill("xuantian-force",1);
	skl4 = (int)me->query_skill("zhengliangyi-sword",1);
        if (skl1<100 || skl2<100 || skl3<100 || skl4<100)
		{
		message_vision("$N����ɽ������ܹ�����������һ��ͷ��\n",me);
		return 1;
		}
	else if (me->query("family/master_id") == "he zudao")
		{
		message_vision("$N����ɽ������ܹ�����������һ��ͷ��\n",me);
		message_vision("ɽ��˵����ԭ�������㡣\n",me);
		message_vision("����δ����һ����ɭɭ���������ֹ�����$Nֻ������ͷһ������\n",me);
		me->move(__DIR__"difu");
		return 1;
		}
	else {
		message_vision("$N����ɽ������ܹ�����������һ��ͷ��\n",me);
		message_vision("û�뵽ɽ���Ƿ���ͻȻ�����ͳ���������\n",me);
		message_vision("����Ȼ����һ��С��ʥ�������ȥ���������ʦȥ�ɣ���\n",me);
		message_vision("����δ����һ����ɭɭ���������ֹ�����$Nֻ������ͷһ������\n",me);
                if(random(3)==2)
		{
			me->unconcious();
                        me->die();
		}
		else
		{
			me->unconcious();
                        me->move(__DIR__"difu");
		}
	return 1;
	}
}

