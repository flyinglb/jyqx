inherit ROOM;
void create()
{
        set("short", "ƮѪ��");
        set("long", @LONG
����Ʈѩɽׯ���������ƮѪ��ۼ��Ÿ�·�������ܣ��������ɸ����ûʣ�
ǽ�Ϲ���һ������(duilian)�����������Ʈѩɽׯ�����ģ�Ʈѩ¥�����ڣ�
�����Ʈѩ����ǧ��Ҫ���룬����������Ʈѩɽׯ�Ŀͷ������й�Ӣ����
��ǲ�õ�ľ�ˡ�
LONG );
	set("no_steal", "1");
	set("no_sleep_room", "1");
        set("no_fight","1"); 
	set("no_clean_up", 0);
        set("item_desc",([
                "duilian" : "����ƮѪ�ټ�ż���ɰ�תͷ�����塣\n",
        ]));
        set("exits", ([
                "east"  : __DIR__"dating",
                "west"  : __DIR__"rest2",
		"northeast" :__DIR__"piaoxue",
        ]));
        setup();
}
