// monk.c

inherit NPC;
int savemu();

void create()
{
        set_name("��ü��ʦ", ({ "huangmei dashi", "dashi", "huangmei" }));
        set("age", 69);
        set("gender", "����");
        set("long", "����һ���������ơ����θߴ����ɮ������ɮ�������Ƴ�ü��
üβ�´������黨�����֡�\n");
        set("attitude", "peaceful");
        set("class", "bonze");

        set("age", 69);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 13);
        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 150);
        set("combat_exp", 1000000);

        set_skill("force", 110);
        set_skill("hunyuan-yiqi", 110);
        set_skill("dodge", 110);
        set_skill("shaolin-shenfa", 110);
        set_skill("finger", 110);
        set_skill("strike", 110);
        set_skill("hand", 110);
        set_skill("claw", 110);
        set_skill("parry", 110);
        set_skill("nianhua-zhi", 110);
        set_skill("sanhua-zhang", 110);
        set_skill("fengyun-shou", 110);
        set_skill("longzhua-gong", 110);
        set_skill("buddhism", 110);
        set_skill("literate", 110);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("finger", "nianhua-zhi");
        map_skill("strike", "sanhua-zhang");
        map_skill("hand", "fengyun-shou");
        map_skill("claw", "longzhua-gong");
        map_skill("parry", "nianhua-zhi");

        prepare_skill("finger", "nianhua-zhi");
        prepare_skill("strike", "sanhua-zhang");

        set("inquiry", ([
                "����" : (: savemu :),
                "��ľ����" : (: savemu :),
                "help" : (: savemu :),
        ]) );

        setup();

        carry_object("/d/wanjiegu/npc/obj/cloth")->wear();
        carry_object("/d/wanjiegu/npc/obj/bu-shoes")->wear();
        carry_object(__DIR__"obj/muyu")->wield();
}

int savemu()
{
        object obj;

        if(obj = present("duan yanqing", environment(this_object()) ) ) {
            command("say �ðɣ����ý�ҩ��ľ���������ס�����졣\n");
            this_object()->kill_ob(obj);
            obj->kill_ob(this_object() );
        } else
            command("say ľ���������棬���ý�ҩ������\n");
        return 1;
}

