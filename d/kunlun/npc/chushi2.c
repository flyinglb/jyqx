
inherit NPC;

string ask_me();

void create()
{
        set_name("��ʦ", ({ "chu shi", "chu" }));
        set("title", "������");
        set("long", 
                "�����ɵ�һ�����ӣ�Ц���еؿ����㣬�����ܺ��Ƶ����ӡ�\n");
        set("gender", "����");
        set("age", 34);
        set("attitude", "peaceful");
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);
        
        set("max_qi", 200);
        set("max_jing", 50);
        set("neili", 0);
        set("max_neili", 0);
        set("jiali", 0);
        set("combat_exp", 500);
        set("shen",0);
        set_skill("force", 10);
        set_skill("dodge", 10);
        set_skill("cuff", 10);
        set_skill("parry", 10);

        create_family("������", 8, "����");
        set("inquiry", ([
                "�Է�" : (: ask_me :),
                "����" : (: ask_me :),
        ]));

        setup();
        carry_object("/clone/cloth/male1-cloth")->wear();        
}

string ask_me()
{
       object me=this_player();
       
       me->set("food", (int)me->max_food_capacity());
       me->set("water", (int)me->max_water_capacity());
  
        return "�����ԣ���ҭס�ˡ�";
}


