inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����Ʈѩɽׯ���������������ۼ��Ÿ�·�������ܣ��������ɸ����ûʣ�
ǽ�Ϲ���һ������(duilian)�����������Ʈѩɽׯ�����ģ�Ʈѩ¥�����ڣ�
�����Ʈѩ����ǧ��Ҫ���룬����������Ʈѩɽׯ�Ŀͷ������й�Ӣ����
��ǲ�õ�ľ�ˡ�
LONG );
	set("no_steal", "1");
	set("no_sleep_room", "1");
        set("no_fight","1"); 
	set("no_clean_up", 0);
        set("item_desc",([
                "duilian" : "������������򣬾��۽������Ƿ�\n",
        ]));
        set("exits", ([
                "east"  : __DIR__"rest1",
                "west"  : __DIR__"dating",
                "northwest"  : __DIR__"piaoxue",
        ]));
        setup();
}
