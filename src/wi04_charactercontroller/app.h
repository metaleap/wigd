#pragma once

#include "../../pch/wi_min_pch.h"
#include ".wi/WickedEngine/wiECS.h"


#define CC_DIR_PATH "../../.wi/Content/scripts/character_controller/"



enum Layers : uint32_t {
  Player = 1 << 0,   // 1
  Npc    = 1 << 1,   // 2
};


class Character {
public:
  XMFLOAT3                                        position;
  XMFLOAT3                                        rotation = XMFLOAT3(0, wi::math::PI, 0);
  bool                                            controllable;
  Layers                                          layerMask;
  float                                           targetRotHorizontal = 0;
  float                                           targetRotVertical   = 0;
  wi::ecs::Entity                                 model;
  std::string                                     state         = "idle";
  wi::ecs::Entity                                 humanoid      = wi::ecs::INVALID_ENTITY;
  wi::ecs::Entity                                 expression    = wi::ecs::INVALID_ENTITY;
  wi::ecs::Entity                                 boneNeck      = wi::ecs::INVALID_ENTITY;
  wi::ecs::Entity                                 boneHead      = wi::ecs::INVALID_ENTITY;
  wi::ecs::Entity                                 boneHandLeft  = wi::ecs::INVALID_ENTITY;
  wi::ecs::Entity                                 boneHandRight = wi::ecs::INVALID_ENTITY;
  wi::ecs::Entity                                 boneFootLeft  = wi::ecs::INVALID_ENTITY;
  wi::ecs::Entity                                 boneFootRight = wi::ecs::INVALID_ENTITY;
  wi::ecs::Entity                                 boneToesLeft  = wi::ecs::INVALID_ENTITY;
  wi::ecs::Entity                                 boneToesRight = wi::ecs::INVALID_ENTITY;
  wi::vector<wi::ecs::Entity>                     objectEntities;
  wi::ecs::Entity                                 root = wi::ecs::INVALID_ENTITY;
  wi::unordered_map<std::string, wi::ecs::Entity> anims;
  XMFLOAT3                                        scale = XMFLOAT3(1, 1, 1);
  float                                           targetHeight;
  float                                           speedWalking  = 0.1f;
  float                                           speedJogging  = 0.2f;
  float                                           speedRunning  = 0.4f;
  float                                           speedJumping  = 8;
  float                                           speedSwimming = 0.2f;
  bool                                            groundIntersect;

  Character(wi::scene::Scene*, wi::scene::TransformComponent*, bool, wi::scene::Scene&, std::string);
  XMFLOAT3 getFacing();
  void     jump(float amount);
  void     turn(XMFLOAT3& direction);
  void     moveDir(XMFLOAT3& direction);
  void     setAnimationAmount(float amount);
  void     update(float delta, wi::unordered_map<wi::ecs::Entity, wi::primitive::Capsule>& characterCapsules);
};


class ThirdPersonCamera {
public:
  Character*      character;
  wi::ecs::Entity camera;

  ThirdPersonCamera(Character* character);
};


class Game : public wi::RenderPath3D {
  bool                   debugDraws          = false;
  float                  slopeThreshold      = 0.2f;   // How much slopeiness will cause character to slide down instead of standing on it
  float                  gravity             = -30.0f;
  bool                   dynamicVoxelization = false;   // Set to true to revoxelize navigation every frame
  Character*             player              = nullptr;
  wi::vector<Character*> npcs;
  wi::unordered_map<wi::ecs::Entity, wi::primitive::Capsule> characterCapsules;
  wi::VoxelGrid                                              voxelGrid;
public:
  void Load() override;
  void Update(float dt) override;
};


class App : public wi::Application {
  Game game;
public:
  void Initialize() override;
};

extern App app;
