// Room: /d/shaolin/chufang2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������һ������������ܴ󣬿���Ҳ����Ϊ�����ֿ��Ե�ʡ�
��ͷ���ڱ��ף�һ�����̴�ֱͨ���ݶ��������ıڱ������̻�Ѭ��
���ڣ�������Ҳ�ǽ��ڽ��ڡ�ǽ�Ƕ����˲����һ�߷���Щɹ��
�����������ȵȡ����ߵ�ǽ�Ұ�����һ�飬¶��Ȯ�������ש������
�ݽǱ��и���(dong)��
LONG );
	set("exits", ([
		"southwest" : __DIR__"houshan",
	]));
	set("item_desc",([
		"brick"	: "��...��...��...��...��...��...��...��\n",
		"dong"	: "ǽ�Ǳ��ǿ��˸��󶴣�����ڳ����ģ���֪ͨ�����\n"
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me;
	mapping fam;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="dong" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "ؤ��" ) 
		{
			message("vision",
				me->name() + "����ؤ�����ǹ���һ�������������˽�ȥ��\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/undersl");
                	message("vision",
				me->name() + "�Ӷ������˽�����\n",
                		environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
	}
}	

