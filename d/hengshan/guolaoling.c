// Room: /d/hengshan/guolaoling.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�⻬�������϶����ֲ������������ΰ��ӣ��Ӿ����Ĵ磬���
����˵����ǵ�������е��Ź����ں�ɽ�޵�ʱ����Сë¿�ɴ�
���졣����·���»��������ò�ǣ¿���У�������Щ��ӡ������ʫ
��:  "������·��ͷ�ǣ���ʯ�ഫ���Ϲ�����������������������
�ż�ʹ��Ħ��" 
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "northup"   : __DIR__"beiyuemiao",
           "westdown"  : __DIR__"tongyuangu",
           "southwest" : __DIR__"hufengkou",
        ]));
        set("outdoors", "hengshan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

