// Room: /liangbaobao/yongdao1.c
// Java. Sep 21 1998

inherit ROOM;

void create()
{
	set("short", "�ڶ�");
	set("long", @LONG
������ǹ�Ĺ��ɽ�Ķ�Ѩ����Ѩ�ﲻ֪����С��,׺�����У�
��Ѩ����һ��ʯ������ֻʯ��֮�⣬�յ�����һ�����С�
LONG );
        set("outdoors", "liangbaobao");
	set("exits", ([
            "out"  : __DIR__"shibi",
            "south"  : __DIR__"jianzhong",
	]));
	set("objects", ([       
                "/u/liangbaobao/yangguo": 1,
                "/u/liangbaobao/shendiao": 1,
	]));
//      set("no_clean_up", 0)
        setup();
}
int valid_leave(object me, string dir)
{
    mapping myfam;
    if( wizardp(me) ) return 1;
    myfam = (mapping)me->query("family");
    if ((!myfam || (myfam["family_name"] != "��Ĺ��")) && (dir == "south"))
      return notify_fail("�ǹ�Ĺ�ɵ��ӣ�����ֹ���ɡ�\n");
    else  return 1;
}
