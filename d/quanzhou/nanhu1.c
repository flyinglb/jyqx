// Room: /d/quanzhou/nanhu1.c
// Date: May 21, 96   Jay

inherit ROOM;

void init();
int do_out();

void create()
{
	set("short", "�����Ϻ�");
	set("long", @LONG
�������̲������Ϻ������ϼ�ֻ�������ε������ϵ��οͺ�
��¥Ů������Ц����ˮ���û�д��Ƕɲ���ȥ�ġ�����֪��˭��
���׶���һЩľ׮��׮��Ǳ��ˮ��֮��һ����ĵط�����ʹ�ǲ���
�Ṧ��������ȥҲ����ˮ��Ư�����ӡ��ƺ�ˮ������Щʲô. ����
����Ǳ(out)�º�ȥ��Ѱʲô, ��Ҳ��֪��������. ֻ�����˴�
���ں����ҵ���ʲô����.
LONG );
	set("exits", ([
		"south"     : __DIR__"yanyu",
                "northwest" : __DIR__ "nanhu",
		"north"	    : __DIR__ "diaoyuchi",
	]));
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_out","out");
}

int do_out()
{
	object me = this_player();
	message_vision("$N����Ծ�𣬿���һ�����﷭����ͷ�½��ϣ��˵�һ��Ǳ����в�����.\n", me);
	me->move("/d/npc/m_weapon/tan/tan1");
	return 1;
}

