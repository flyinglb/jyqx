// muwu1.c
// by shilling 97.2

inherit ROOM;

void create()
{
	set("short", "ľ��");
	set("long", @LONG
������һ�䲻���ľͷ���ӣ�������ȸ��С����ؾ�ȫ��������ֻ����
������ذ��ż����Ҿߣ�����Ҳ���Ե���ôС��
LONG );
	set("exits", ([
		"north" : __DIR__"xiaodao5",
                "south" : __DIR__"yaogu",
	]));
 	set("objects", ([
		__DIR__"npc/kanggl": 1,
	]));
//	set("no_clean_up", 0);
	setup();
}
//int valid_leave(object me, string dir)
//{
//         if( dir=="south" && !wizardp(me) )
//        return notify_fail("������!��ԭ��!\n");
//        return ::valid_leave(me, dir);
//}
