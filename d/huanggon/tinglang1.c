// tinglang1.c ����

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ܵ���������.������ϲ�˵Ļ���,վ�����,��Լ���õ�����
������Ů����Ц������,�����������������,�Եþ�������,��������
�Ĺ��ͦ�ϵ�.�м�����Ա������ŵ�վ�����,���Ż����ټ�.
LONG
        );
        set("exits", ([
        "north" : __DIR__"shufang",
        "south" : __DIR__"tinglang2",
        ]));
        set("outdoors", "huangon");
        setup();
        replace_program(ROOM);
}
