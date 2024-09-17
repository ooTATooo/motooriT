#include "Framework/KdFramework.h"

#include "KdLessonShader.h"

//================================================
// �`�揀��
//================================================

// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// /////
// �A�e������I�u�W�F�N�g�̕`��̒��O�����i�s�����ȕ��̂�L�����N�^�̔|���S���j
// ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
// �V�F�[�_�[�̃p�C�v���C���ύX
// LitShader�Ŏg�p���郊�\�[�X�̃o�b�t�@�[�ݒ�
// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// /////
void KdLessonShader::BeginLessonShader()
{
    // ���_�V�F�[�_�[�̃p�C�v���C���ύX
    if (KdShaderManager::Instance().SetVertexShader(m_VS))
    {
        KdShaderManager::Instance().SetInputLayout(m_inputLayout);
    }

    // �s�N�Z���V�F�[�_�[�̃p�C�v���C���ύX
    if (KdShaderManager::Instance().SetPixelShader(m_PS))
    {
    }
}

// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// /////
// �A�e����I�u�W�F�N�g�̕`��C��
// ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== ===== =====
// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// ///// /////
void KdLessonShader::EndLessonShader()
{
}

bool KdLessonShader::Init()
{
    //-------------------------------------
    // ���_�V�F�[�_
    //-------------------------------------
    {
        // �R���p�C���ς݂̃V�F�[�_�[�w�b�_�[�t�@�C�����C���N���[�h
#include "KdLessonShader_VS.shaderInc"

        // ���_�V�F�[�_�[�쐬
        if (FAILED(KdDirect3D::Instance().WorkDev()->CreateVertexShader(compiledBuffer, sizeof(compiledBuffer), nullptr, &m_VS))) {
            assert(0 && "���_�V�F�[�_�[�쐬���s");
            Release();
            return false;
        }

        // �P���_�̏ڍׂȏ��
        std::vector<D3D11_INPUT_ELEMENT_DESC> layout = {
            { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,   0,  0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,	    0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT,   0, 20, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            { "COLOR",    0, DXGI_FORMAT_R8G8B8A8_UNORM,    0, 32, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        };

        // ���_���̓��C�A�E�g�쐬
        if (FAILED(KdDirect3D::Instance().WorkDev()->CreateInputLayout(
            &layout[0],				// ���̓G�������g�擪�A�h���X
            layout.size(),			// ���̓G�������g��
            &compiledBuffer[0],		// ���_�o�b�t�@�̃o�C�i���f�[�^
            sizeof(compiledBuffer),	// ��L�̃o�b�t�@�T�C�Y
            &m_inputLayout))
            ) {
            assert(0 && "CreateInputLayout���s");
            Release();
            return false;
        }

    }

    //-------------------------------------
    // �s�N�Z���V�F�[�_
    //-------------------------------------
    {
#include "KdLessonShader_PS.shaderInc"

        if (FAILED(KdDirect3D::Instance().WorkDev()->CreatePixelShader(compiledBuffer, sizeof(compiledBuffer), nullptr, &m_PS))) {
            assert(0 && "�s�N�Z���V�F�[�_�[�쐬���s");
            Release();
            return false;
        }
    }

    return true;
}

void KdLessonShader::Release()
{
    KdSafeRelease(m_VS);
    KdSafeRelease(m_PS);
    KdSafeRelease(m_inputLayout);
}

void KdLessonShader::DrawMesh(const KdMesh* mesh, const Math::Matrix& mWorld, const std::vector<KdMaterial>& materials,
                              const Math::Vector4& col, const Math::Vector3& emissive)
{
    if (mesh == nullptr) { return; }

    // ���b�V���̒��_���]��
    mesh->SetToDevice();

    // �S�T�u�Z�b�g
    for (UINT subi = 0; subi < mesh->GetSubsets().size(); subi++)
    {
        // �ʂ��P���������ꍇ�̓X�L�b�v
        if (mesh->GetSubsets()[subi].FaceCount == 0)continue;

        //-----------------------
        // �T�u�Z�b�g�`��
        //-----------------------
        mesh->DrawSubset(subi);
    }
}

void KdLessonShader::DrawModel(const KdModelData& rModel, const Math::Matrix& mWorld,
                               const Math::Color& colRate, const Math::Vector3& emissive)
{
    auto& dataNodes = rModel.GetOriginalNodes();

    // �S�`��p���b�V���m�[�h��`��
    for (auto& nodeIdx : rModel.GetDrawMeshNodeIndices())
    {
        // �`��
        DrawMesh(dataNodes[nodeIdx].m_spMesh.get(), dataNodes[nodeIdx].m_worldTransform * mWorld,
            rModel.GetMaterials(), colRate, emissive);
    }
}
