// Room: /d/shaolin/zhushe.c
// Date: YZC 96/01/19
// Dat:  Cleansword 96/02/20

inherit ROOM;

int do_remove();
void fainting(object me, object ob);
string look_stone();

/* (move stone) ����ʯ������������һϢ����������������
��շ�ħȦǰ��ε��߷�(western)��˵��ͷһ�ᣬ���ˡ������
ѧ���ڹ���������ѧ�ڹ���(life heal)֮������������һ������
����˵�������߷�(news)�����Ҹ�֪���Թ��߷����ڳ���Ī����
δ��˵��δ������ˡ�����Լ��ҳ��δ�����ͷ��������ȥ��
������һ��ש���Ͽ̳��Թ��߷�����*/

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǽ����õ�ũ�����ᡣȦ�����ż�ͷ��������Ѿ��ɺ��ˣ�
����Ҳ��ʼ��ù���á����ںö���û���������ڵķ�㣬��������
����һ�ɶ�����ݽǶ���һ���ʯ��(stone)�����а��˸ߡ�
LONG );
	set("exits", ([
		"southeast" : __DIR__"houshan",
	]));
	set("item_desc",([
		"stone"		:	(: look_stone :),
	]));
	set_temp("available",1);
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_move", "move");
}

int do_move(string arg)
{
//        string dir;
	object me,ob;

	if( !arg || arg=="" || !query_temp("available") ) return 0;

	if( arg=="stone" && query_temp("available")) {
		write("��������ʯ��һ���ذῪ��ͻȻ�����������Ÿ�����һϢ������ !\n\n");
	        delete_temp("available");
	}


	me = new(__DIR__"npc/lao-qiao",1);
	me->move(__DIR__"zhushe");

	ob = this_player();	

	message_vision("���˶϶�������˵��: ��������������...��������ɽ����...��
��������...������...������...������...������...��������......\n\n", ob);

	message_vision("�������촽���˶����ƺ�����˵Щʲ�ᣬȴ��������֧�������˹�ȥ��\n", ob);

	me->unconcious();

	remove_call_out("fainting");
	call_out("fainting", 20, me, ob);

	return 1;
}

void fainting(object me, object ob)
{

	if ( (int)me->query("qi") <= 50 ) 
	{
		message_vision("���������������˹�����˵��: л...л......��\n",ob);
		me->die();
	}
	else
	{
		message_vision("\n���������˹�����˵��: ����������������������......��·��ש......\n\n",ob);
		message_vision("˵���Դ�������ش�����ȥ......",ob);
		me->die();
	}

	return;
}

string look_stone()
{
	return "����һ���ʯ�飬����ǽ�űߣ���֪����ʲ���ó���\n";
}
