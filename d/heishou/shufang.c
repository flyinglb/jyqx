inherit ROOM;
void create()
{
        set("short", "�鷿");
        set("long", @LONG
����ׯ�����鷿��������Ŀ��ȫ��ʫ��伮���������ϰ���
���ͭ���������������ǹ�����Ϲ���һ��ˮī���������Ǹ�
��������������֮ҹ��ͥ������
LONG );
        set("no_sleep_room", "1");
        set("no_clean_up", 0);
        set("exits", ([
                "east"  : __DIR__"qianyuan",
        ]));
        setup();
}
