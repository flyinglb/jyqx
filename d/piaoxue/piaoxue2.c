inherit ROOM;
void create()
{
        set("short", "Ʈѩ¥��¥");
        set("long", @LONG
������Ʈѩɽׯ��ִ�����ģ�����������һ��ľ��(sign)
���������ǳ���Ժ��������Ʈѩɽׯ�Ļ����ã�������ִ��
�ã�������������ׯ��ĵ��ӵģ���������Ƿ����Ʈѩ
�����뾡���뿪��
LONG );
	set("no_steal", "1");
	set("no_sleep_room", "1");
        set("no_fight","1"); 
	set("no_clean_up", 0);
	set("item_desc",([
                "sign" : "����Ժ�صأ������ô�\n",
        ]));
        set("exits", ([
                "east"  : __DIR__"oldguy1",
                "west"  : __DIR__"oldguy2",
                "south"  : __DIR__"hufa",
                "north"  : __DIR__"zhifa",
                "up"  : __DIR__"piaoxue3",
                "down"  : __DIR__"piaoxue",
        ]));
        setup();
}