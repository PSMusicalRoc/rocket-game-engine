#include "init.hpp"
#include "Common/Globals.hpp"

void mover_left()
{
    auto mover = find_entities_by_label("mover").at(0);
    Movement2DComponent* movement = std::any_cast<Movement2DComponent>(&mover->component_list.at(2));
    SpriteRenderer* sprt = std::any_cast<SpriteRenderer>(&mover->component_list.at(0));

    movement->move_left = true;
    sprt->switch_animation("walk_left");
}

void mover_right()
{
    auto mover = find_entities_by_label("mover").at(0);
    Movement2DComponent* movement = std::any_cast<Movement2DComponent>(&mover->component_list.at(2));
    SpriteRenderer* sprt = std::any_cast<SpriteRenderer>(&mover->component_list.at(0));

    movement->move_right = true;
    sprt->switch_animation("walk_right");
}

void mover_down()
{
    auto mover = find_entities_by_label("mover").at(0);
    Movement2DComponent* movement = std::any_cast<Movement2DComponent>(&mover->component_list.at(2));
    SpriteRenderer* sprt = std::any_cast<SpriteRenderer>(&mover->component_list.at(0));

    movement->move_down = true;
    sprt->switch_animation("walk_down");
}

void mover_up()
{
    auto mover = find_entities_by_label("mover").at(0);
    Movement2DComponent* movement = std::any_cast<Movement2DComponent>(&mover->component_list.at(2));
    SpriteRenderer* sprt = std::any_cast<SpriteRenderer>(&mover->component_list.at(0));

    movement->move_up = true;
    sprt->switch_animation("walk_up");
}

void mover_left_keyup()
{
    auto mover = find_entities_by_label("mover").at(0);
    Movement2DComponent* movement = std::any_cast<Movement2DComponent>(&mover->component_list.at(2));
    SpriteRenderer* sprt = std::any_cast<SpriteRenderer>(&mover->component_list.at(0));

    movement->move_left = false;
    sprt->switch_animation("idle_left");
}

void mover_right_keyup()
{
    auto mover = find_entities_by_label("mover").at(0);
    Movement2DComponent* movement = std::any_cast<Movement2DComponent>(&mover->component_list.at(2));
    SpriteRenderer* sprt = std::any_cast<SpriteRenderer>(&mover->component_list.at(0));

    movement->move_right = false;
    sprt->switch_animation("idle_right");
}

void mover_down_keyup()
{
    auto mover = find_entities_by_label("mover").at(0);
    Movement2DComponent* movement = std::any_cast<Movement2DComponent>(&mover->component_list.at(2));
    SpriteRenderer* sprt = std::any_cast<SpriteRenderer>(&mover->component_list.at(0));

    movement->move_down = false;
    sprt->switch_animation("idle_down");
}

void mover_up_keyup()
{
    auto mover = find_entities_by_label("mover").at(0);
    Movement2DComponent* movement = std::any_cast<Movement2DComponent>(&mover->component_list.at(2));
    SpriteRenderer* sprt = std::any_cast<SpriteRenderer>(&mover->component_list.at(0));

    movement->move_up = false;
    sprt->switch_animation("idle_up");
}

void init_mover()
{
    auto mover = create_entity(Globals::screen_width / 2, Globals::screen_height / 2);
    mover->labels.emplace_back("mover");

    add_component_to_entity<SpriteRenderer>(SpriteRenderer("idle_left", Animation(Spritesheet("res/img/kiwi/kiwi_left.png"))), mover);
    SpriteRenderer* sprt = std::any_cast<SpriteRenderer>(&mover->component_list.at(0));

    add_frame_to_animation(sprt->animations.at("idle_left").get(), {0, 0, 32, 32});

    add_animation_to_spriterenderer(sprt, "idle_right", Animation(Spritesheet("res/img/kiwi/kiwi_right.png")));
    add_frame_to_animation(sprt->animations.at("idle_right").get(), {64, 0, 32, 32});

    add_animation_to_spriterenderer(sprt, "idle_up", Animation(Spritesheet("res/img/kiwi/kiwi_up.png")));
    add_frame_to_animation(sprt->animations.at("idle_up").get(), {0, 0, 32, 33});

    add_animation_to_spriterenderer(sprt, "idle_down", Animation(Spritesheet("res/img/kiwi/kiwi_down.png")));
    add_frame_to_animation(sprt->animations.at("idle_down").get(), {0, 0, 32, 32});

    add_animation_to_spriterenderer(sprt, "walk_left", Animation(Spritesheet("res/img/kiwi/kiwi_left.png")));

    for (int i = 0; i < 7; i++)
    {
        for (int _ = 0; _ < 4; _++)
        {
            add_frame_to_animation(sprt->animations.at("walk_left").get(), {
                i * 32,
                0,
                32,
                32
            });
        }
    }

    add_animation_to_spriterenderer(sprt, "walk_right", Animation(Spritesheet("res/img/kiwi/kiwi_right.png")));

    for (int i = 0; i < 7; i++)
    {
        for (int _ = 0; _ < 4; _++)
        {
            add_frame_to_animation(sprt->animations.at("walk_right").get(), {
                i * 32,
                0,
                32,
                32
            });
        }
    }

    add_animation_to_spriterenderer(sprt, "walk_up", Animation(Spritesheet("res/img/kiwi/kiwi_up.png")));

    for (int i = 0; i < 8; i++)
    {
        for (int _ = 0; _ < 4; _++)
        {
            add_frame_to_animation(sprt->animations.at("walk_up").get(), {
                i * 32,
                0,
                32,
                33
            });
        }
    }

    add_animation_to_spriterenderer(sprt, "walk_down", Animation(Spritesheet("res/img/kiwi/kiwi_down.png")));

    for (int i = 0; i < 8; i++)
    {
        for (int _ = 0; _ < 4; _++)
        {
            add_frame_to_animation(sprt->animations.at("walk_down").get(), {
                i * 32,
                0,
                32,
                32
            });
        }
    }

    sprt->do_clip = true;
    sprt->switch_animation("idle_left");
    sprt->pos = {0, 0, 128, 128};


    add_component_to_entity<ControlsComponent>(ControlsComponent(), mover);
    ControlsComponent* mover_controls = std::any_cast<ControlsComponent>(&mover->component_list.at(1));

    add_component_to_entity<Movement2DComponent>(Movement2DComponent(50), mover);

    set_keydown_callback(mover_controls, SDL_SCANCODE_W, mover_up);
    set_keydown_callback(mover_controls, SDL_SCANCODE_S, mover_down);
    set_keydown_callback(mover_controls, SDL_SCANCODE_A, mover_left);
    set_keydown_callback(mover_controls, SDL_SCANCODE_D, mover_right);

    set_keyup_callback(mover_controls, SDL_SCANCODE_W, mover_up_keyup);
    set_keyup_callback(mover_controls, SDL_SCANCODE_S, mover_down_keyup);
    set_keyup_callback(mover_controls, SDL_SCANCODE_A, mover_left_keyup);
    set_keyup_callback(mover_controls, SDL_SCANCODE_D, mover_right_keyup);
}

void kiwi_end_dialogue()
{
    SharedPtrEntity kiwi = find_entities_by_label("kiwi")[0];
    int index = find_entity_position(kiwi);
    GLOBAL_ENTITY_LIST.erase(GLOBAL_ENTITY_LIST.begin() + index);

    init_mover();
}

void kiwi_continue_dialogue()
{
    SharedPtrEntity kiwi = find_entities_by_label("kiwi")[0];
    
    auto kiwi_text = std::any_cast<AnimatedTextRenderer>(&kiwi->component_list.at(1));

    kiwi_text->advance_dialogue();
}

void init()
{
    /*
    * FPS Entity
    */

    auto fps_ent = create_entity(0, 0);
    fps_ent->labels.emplace_back("ui");
    fps_ent->labels.emplace_back("fps");
    add_component_to_entity<TextRenderer>(TextRenderer(std::string("300"), Fonts::ARIAL), fps_ent);
    Logger::log(LogLevel::INFO, "Added component to FPS Entity!");
    TextRenderer* txt = std::any_cast<TextRenderer>(&fps_ent->component_list.at(0));
    txt->size_and_pos.h = 100;
    txt->size_and_pos.w = 1000;







    /*
    * Kiwi
    */
   
    auto kiwi = create_entity(100, 700);
    kiwi->labels.emplace_back("kiwi");
    //auto shared = std::make_shared<Animation>(Animation(Spritesheet("res/img/kiwi/Kiwi_Megaman_Battle_Network.png")));
    add_component_to_entity<SpriteRenderer>(SpriteRenderer("idle", Animation(Spritesheet("res/img/kiwi/Kiwi_Megaman_Battle_Network.png"))), kiwi);
    SpriteRenderer* kiwi_sprite = std::any_cast<SpriteRenderer>(&kiwi->component_list.at(0));
    kiwi_sprite->do_clip = true;

    kiwi_sprite->pos = {0, 0, 200, 200};
    kiwi_sprite->switch_animation("idle");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                add_frame_to_animation(kiwi_sprite->animations.at("idle").get(), {480 * j, 480 * i, 480, 480});
            }
        }
    }

    add_animation_to_spriterenderer(kiwi_sprite, "whale_mom", Animation(Spritesheet("res/img/whale_mom/Whale_Mom_Megaman_Battle_Network_New.png")));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                add_frame_to_animation(kiwi_sprite->animations.at("whale_mom").get(), {480 * j, 480 * i, 480, 480});
            }
        }
    }


    add_component_to_entity<AnimatedTextRenderer>(AnimatedTextRenderer(100), kiwi);
    
    AnimatedTextRenderer* kiwi_text = std::any_cast<AnimatedTextRenderer>(&kiwi->component_list.at(1));

    kiwi_text->messages.emplace_back(Message("Hi there, this is a test of the animated scrolling text!\n"
                                    "Hopefully, it's also multiline as well!\n"
                                    "Thank you Asher for making the poggers art! :PogU:"));
    kiwi_text->messages.at(0).font = Fonts::SMALL_ARIAL;
    
    kiwi_text->messages.emplace_back(Message("Test2"));
    kiwi_text->messages.at(1).font = Fonts::SMALL_ARIAL;
    kiwi_text->messages.at(1).message_done_callback = [](){
        
        auto kiwi = find_entities_by_label("kiwi")[0];
        auto kiwi_sprite = std::any_cast<SpriteRenderer>(&kiwi->component_list.at(0));
        kiwi_sprite->switch_animation("whale_mom");
        };

    kiwi_text->messages.emplace_back(Message("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB"));
    kiwi_text->messages.at(2).font = Fonts::SMALL_ARIAL;


    kiwi_text->size_and_pos.x = 305;
    kiwi_text->size_and_pos.y = 700;
    kiwi_text->end_of_dialogue_callback = kiwi_end_dialogue;


    add_component_to_entity<ControlsComponent>(ControlsComponent(), kiwi);
    ControlsComponent* kiwi_controls = std::any_cast<ControlsComponent>(&kiwi->component_list.at(2));

    set_keydown_callback(kiwi_controls, SDL_SCANCODE_A, kiwi_continue_dialogue);
}