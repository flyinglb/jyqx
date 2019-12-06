// azhu.c

inherit NPC;
int inquiry_tanqin();

void create()
{
        set_name("����", ({ "azhu", "zhu" }));
        set("long",
                "���Ǹ������µ�Ů�ɣ���Լʮ�߰��꣬һ��������Ƥ��������\n"
                "һ�Ŷ쵰���������鶯������һ�����˷��ϡ�\n");

        set("gender", "Ů��");
        set("age", 17);
        set("shen_type", 1);

        set("neili", 200);
        set("max_neili", 200);
        set("max_qi", 160);
        set("max_jing", 160);
        set_skill("force", 40);
        set_skill("unarmed", 40);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_skill("sword", 30);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set_temp("apply/damage", 5);

        set("combat_exp", 10000);
        set("inquiry",([
            "����ɽׯ" : "�ҲŲ���ȥ����ɽׯ��������̫�Ե���!\n",
            "������" : "����ֻ��������������ǹ��ӣ�Ҳ��֪��������ô����!\n",
            "����" : "��СѾͷҲ��ֻ���Ķ�ȥ�ˡ�\n",
            "����" : ( : inquiry_tanqin : ),
        ]) );
        setup();
        carry_object(__DIR__"obj/goldring")->wear();
        carry_object(__DIR__"obj/necklace")->wear();
        carry_object(__DIR__"obj/changjian")->wield();
        carry_object(__DIR__"obj/pink_cloth")->wear();
        carry_object(__DIR__"obj/flower_shoe")->wear();
//      carry_object("clone/misc/mask");
}

int inquiry_tanqin()
{
        object me=this_player();
message_vision("����˵������λ"+ RANK_D->query_respect(me)+ "��ô�����ˣ����Ҿ�Ϊ�㵯��һ����
                 \nֻ�����������������㲻�ɵĳ��ˡ�\n", me );
//        ϸϸƷ�������������ܵ�<<���糱ˮ>>!!!\n 
        message_vision("����һ�����ˣ������򸣣�˵�����ֳ��ˡ�\n", me );
        return 1;
}
