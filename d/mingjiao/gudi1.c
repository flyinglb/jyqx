// Room: /d/mingjiao/gudi1.c

inherit ROOM;

void create()
{
	set("short", "���عȵ�");
	set("long", @LONG
ǰ����һ������Ҳ�ƵĴ�ɽ�ڡ���ǰãã�ƺ�������ȥ·����
����������һ������Կյļ���ƽ̨�ϡ���ƽ̨����ʮ���ɷ�Բ��
���ǰ����ٿգ��ϼȲ��ã����ֲ��ܣ���������·һ�������ƽ̨
�ϰװ����Ķ��Ǳ�ѩ���������֣�����Ұ�ޡ�
LONG );
	set("outdoors", "mingjiao");
	setup();
}
void init()
{
	add_action("do_climb","climb");
}
int do_climb()
{
	int n = this_player()->query_skill("dodge",1);
	message_vision("$N������һ��������������ѩ����������\n", this_player());
	if(n >40)
	{
		message_vision("$N���˰��죬����ϥ�Ƕ��ѱ���������Ѫ���죬��
������������\n", this_player());
		this_player()->move(__DIR__"gudi2");
	}
	else
	{
		message_vision("$N����һ�ᣬ̫���ˣ���С�Ļ�����������!û�취��
���������ɡ�\n", this_player());
		this_player()->receive_damage("qi",15);
		this_player()->receive_wound("qi",10);
	}
	return 1;
}
