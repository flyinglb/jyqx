inherit ITEM;
inherit F_FOOD;

void create()
{
     set_name("��ѩ����", ({ "gao" }));
     set_weight(1000);
     if( clonep() )
            set_default_object(__FILE__);
     else {
          set("long", "����һ���㣬����ʳ��������\n");
          set("unit", "��");
          set("value", 50);
          set("food_remaining", 6);
          set("food_supply", 100);
     }
}
