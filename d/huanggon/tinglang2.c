// tinglang2.c ����

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ܵ���������.������ϲ�˵Ļ���,վ�����,��Լ���õ�����
������Ů����Ц������,�����������������,�Եþ�������,��������
�Ĺ��ͦ�ϵ�.
LONG
        );
        set("exits", ([
        "north" : __DIR__"tinglang1",
        "south" : __DIR__"taihedai",
        "west" : __DIR__"tinglang3",
        ]));
        set("outdoors", "huangon");
        setup();
        replace_program(ROOM);
}
