// gao.c
inherit ITEM;
inherit F_FOOD;

void create()
{
     set_name("��ɫ����", ({ "gao" }));
    set_weight(1500);
    if( clonep() )
            set_default_object(__FILE__);
    else {
          set("long", "��ɫ������״����,�ƺ�����������һ��\n");
          set("unit", "��");
          set("value", 50);
          set("food_remaining", 4);
          set("food_supply", 20);
     }
}

