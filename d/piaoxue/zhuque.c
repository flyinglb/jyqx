inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ��ͨ����ȸ�õĳ��ȣ���ֻ������������
�������ף�ʹ���᲻���뿪��
LONG );
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
        set("exits", ([
                "south"  : __DIR__"dayuan3",
                "north"  : __DIR__"piaoxue",
        ]));
        setup();
}