inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������Ʈѩɽׯ����ׯ������ס�ĵط���
��Ȼ������ûʲô����Ĳ��ã�������
Ȼ���Կ�����������������ݵĲ�ͬѰ����
LONG );
	set("no_steal", "1");
	set("sleep_room", "1");
	set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"piaoxue3",
        ]));
        setup();
}
