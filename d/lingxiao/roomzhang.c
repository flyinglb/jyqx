// Room: roomzhang.c

inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG 
�߽��������������ǰ���Ǵ��СС��ҩ�ޡ�������ס��
�������ǵ��������������꣬��Ϊ�˺�������԰����ڷ��ĵذ�
����������һЩϡ��ҩ������񽻸�������������˵����������
�������ã�������һЩ����ҩ�Ƹ��Ǽһ�ȡ�
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "north"  : __DIR__"zoulang2", 
        ]));
        set("objects", ([  
                __DIR__"npc/zhang" : 1,
                __DIR__"obj/icesword" : 3,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

