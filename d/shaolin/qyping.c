// Room: /d/shaolin/qyping.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "����ƺ");
	set("long", @LONG
����������Ҿ�������Ŀ��ȥ��ֻ���������ƣ���������룻
��ɽ�δ䣬�ƽ�����졣ɽ������ٲ���к���£�ʯ���������ۣ�
����һ�����棬���˷׷����ϣ��������Ρ���ǰ��ƽ���ϴ�ݲ�
�����������þ���Χ��һȦ��Ȧ�����ƺ���ʲô�������������⡣
LONG );
	set("exits", ([
		"southdown" : __DIR__"shulin14",
		"enter" : __DIR__"fumoquan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
}

int valid_leave(object me, string dir)
{
/*
        if ( dir == "enter" && !wizardp(me) ) 
                return notify_fail("�����̤��ȥ������ӿ��һ��ǿ��������������˳���\n");
*/
        if ( dir == "enter" ) {
	if ( present("fumo dao", me) || present("jingang zhao", me) 
	  || present("fumo dao", environment(me)) || present("jingang zhao", environment(me)) )
		return notify_fail("ֻ����������˵��: �����ϻ��������˴����˿���Я�ر���������룬\nˡ���ĵ�ʧ���ˡ�\n");
      if( me->query("combat_exp") < 350000 )
 return notify_fail("�㻹���ᣬ��Ҫȥ��������\n");
    }
         return ::valid_leave(me, dir);
}

