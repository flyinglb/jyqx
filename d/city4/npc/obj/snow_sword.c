/*  <SecCrypt CPL V3R05>  */
 
#include  <weapon.h>

inherit  SWORD;

void  create()
{
                set_name("���ѩ�轣",  ({  "snowsword",  "xue  jian",  "sword"  })  );
                set_weight(400);
                if(  clonep()  )
                                set_default_object(__FILE__);
                else  {
                                set("unit",  "��");
                                set("value",  700);
                                set("material",  "steel");
                                set("long",  "����һ����������Ľ�������ϸ���������ȷ�����\n");
                                set("wield_msg",  "$N���һ�ѽ���ϸ���Ľ����������С�\n");
                                set("unequip_msg",  "$N�������е�$n��\n");
                                set("weapon_prop/courage",  4);
                }
                init_sword(40);
                setup();
}

