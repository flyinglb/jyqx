
inherit NPC;

void create()
{
        set_name(HIW"��ˮ��"NOR, ({"Sno"}));
	set("nickname",HIR"��"+HIW+"����¥"+HIR+"��"+BLK+"�ڰ���ʹ "+HIY+"�Ե��޵�"NOR);
	set("gender", "����");
	set("age", 25);
	set("per", 28);
	set("long", 
                  "����������ˮ����׳ʿһȥ�ⲻ������\n"
                  "����\n");
                             
	setup();
        
	carry_object("/d/city2/obj/jinduan")->wear();
}
