inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ�ڼ����ˮ��������ˮ�����Ͽ���ֻ����ԲԲ���������ô��
��������(wall)�����ǻ��������̦��һ����ꤵ���һ������(string)��
����ϵ��һ��ľͰ(mutong)��ľͰ���ڿ��У�����ܽ���ֻ��һ��Ϳ�
�Թ����š�
LONG );
        set("outdoors", "huanggon");
	set("no_clean_up", 0);
	set("resource/water", 1);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
	add_action("do_jump", "tiao");
	add_action("do_jump", "jump");
	add_action("do_reach", "reach");
}

int do_reach(string arg)
{
        object me;
        me = this_player();
        if (!arg||arg=="") return 0;
	if( arg=="mutong") {
		message_vision(
		"\n$N����ȥץľͰ�������ǲ�һ�㹻�ţ�Ҫ������һ��ͺ��ˡ�\n", me);
	}
	if( arg=="string") {
		message_vision(
		"\n$N����ȥץ�����������ǲ�һ�㹻�ţ�Ҫ������һ��ͺ��ˡ�\n", me);
	}
return 1;
}

int do_climb(string arg)
{
        object me;
        me = this_player();
	if (!arg && (arg != "wall")&& (arg != "string"))
		return notify_fail("��Ҫ��ʲô��\n");
	if( arg=="wall" ) {
		message_vision(
		"\n$N�������˺ü��Σ����Ǿ���̫������ôҲ�ϲ�ȥ��\n", me);
	}
	if( arg=="string" ) {
        if(me->query_temp("hasjump"))
	{
        me->delete_temp("hasjump");
        message_vision(
	"$N˳�ų�������������������������ؼ����ա�\n", me);
        message_vision(
	"$N���쳤Ц���������Ͼ�û���������ɵ��°���������������\n", me);
	me->move("/d/huanggon/houyuan");
	}
	else return notify_fail("\n�㹻���š�\n");
	} 
return 1;
}

int do_jump(string arg)
{
        object me;
        me = this_player();
	if (!arg && (arg != "mutong") && (arg != "string"))
		return notify_fail("��Ҫ���Ƕ�����\n");
		message_vision(
		"\n$N����һ�����������͵�һ����һ��ץס��ľͰ��\n", me);
		message_vision(
		"ֻ����µµһ�����죬ľͰһ��������ͷ��$N���˼��ˡ�\n", me);
                me->set_temp("hasjump",1);
	return 1;
}



