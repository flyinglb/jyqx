// fu-midao.c �ܵ�
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
�����Ǻ�Ա�������µ��ܵ�����˵���軧���ڽɲ����⣬
����Ա���צ��ץ���������������ܺ�����һЩǳ��ɫ�ɵ�Ѫ
�գ������м�����һ������ë���Ȼ���������㲻�ɵ���Щ����
���������뻹�ǸϿ��뿪����ɡ�
LONG
        );
        set("exits", ([
                "southeast" : __DIR__"fu-mishi",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
