// Room: /d/mingjiao/gudi5.c

inherit ROOM;
void create()
{
	set("short", "�����ɾ�");
	set("long", @LONG
�������˶���ֻ࣬���ͱ�����һ�����ٲ�������£�������
ѩ�ڶ��ɣ���������������һ��������������׳�����ٲ�й��һ��
�峺���̵���̶(tan )֮�У�̶ˮȴҲ����������������йˮ��ȥ
·��������˰��Σ�һ��ͷ����������Ⱦ������̦���࣬��������
������Ӳ�ݸ��Ƶ�Ѫ�ۣ�����߽�̶�ߣ�����Ь�࣬���㵽̶ˮ��
ȥϴ��(xidi)��
LONG );
	set("outdoors", "mingjiao");
	set("exits", ([
		"east" : __DIR__"gudi3",
	]));
	set("fish_count",2);
	set("item_desc", ([
		"tan" : "�㸽��̶�ߣ�������ȥ��ֻ�����̵�ˮ��ʮ��������������ζ���\n",
	]));
	setup();
}
void init()
{
	add_action("do_xidi", "xidi");
}
int do_xidi()
{
	object fish, me = this_player();
	if ((this_player()->query_dex()<25) || query("fish_count")<=0)
message_vision("$Nϴ��һ�ᣬͻȻ����һ����̶������һβ����㣬����һ�߶�
����$Næ����ȥץ����Ȼ����������ȴһ�������ˡ�\n", me);
	else
	{
message_vision("̶������һβ����㣬����һ�߶೤��$Næ����ȥץ��һ�Ѱ���
߬�����ġ�\n", me);
		add("fish_count",-1);
	}
	fish = new(__DIR__"obj/fish");
	fish -> move(me);
	return 1;
}
