// Room: /d/mingjiao/xuantianshi.c


inherit ROOM;

void create()
{
	set("short", "����ʯ");
	set("long", @LONG
��ʯ��Զ����ֻ���ƺ���ã�����վ�������������һ��������
ǧ���һ�ɴ�ý�ɽ����������ʯ��������ഫ˵���ഫ���̵�
��ʮ��������������Ӱ������(Doll)Ϊ������֮�ѣ������ڴˣ���
��һ����ѧ��Ǭ����Ų�ơ��Ӵ�ʧ����������֮���ڴ�ƾ����Ī
�����ᣬ��������ǴӴ�ʯ��(tiao)�£���Ѱ�ҡ�Ǭ����Ų�ơ���
����ȴ��û�����ܰ�Ȼ���顣
LONG );
	set("exits", ([
		"down" : __DIR__"shanlu3",
	]));
	set("item_desc", ([
		"doll" : "һ�����Բ�˹�̵ܽĽ�����\n",
	]));

	set("outdoors", "mingjiao");
	setup();
}
void init()
{
	add_action("do_tiao","tiao");
}
int do_tiao(object me)
{
	me = this_player();
	message_vision("$N������Ƭ���͵�����Ԩ���£���ӰԽƮԽС��\n", me);
	if (me->query_dex()>25)
	{
		me->move(__DIR__"gudi1");
	}
	else if (me->query_dex()>20)
	{
		me->move(__DIR__"gudi1");
		me->unconcious();
	}
	else
	{
		me->move(__DIR__"gudi1");
		me->die();
	}
	return 1;
}

