inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ��ͨ���׻��õĳ��ȣ���ֻ������������
�������ף�ʹ���᲻���뿪��
LONG );
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"piaoxue",
                "west"  : __DIR__"dayuan2",
        ]));
        setup();
}