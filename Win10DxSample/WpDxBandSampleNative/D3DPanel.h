﻿//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
//
//*********************************************************

#pragma once
#include "pch.h"
#include "DirectXPanelBase.h"
#include "StepTimer.h"
#include "ShaderStructures.h"

namespace WpDxBandSampleNative
{
    // Hosts a DirectX rendering surface that draws a spinning 3D cube using Direct3D.

    [Windows::Foundation::Metadata::WebHostHidden]
    public ref class D3DPanel sealed : public WpDxBandSampleNative::DirectXPanelBase
    {
    public:
        D3DPanel();

        void StartRenderLoop();
        void StopRenderLoop();

		property double Pitch;
		property double Yaw;
		property double Roll;

		property double Scale;

    private protected:

        virtual void Render() override;
        virtual void CreateDeviceResources() override;
        virtual void CreateSizeDependentResources() override;

        Microsoft::WRL::ComPtr<IDXGIOutput>                 m_dxgiOutput;

        Microsoft::WRL::ComPtr<ID3D11RenderTargetView>      m_renderTargetView;
        Microsoft::WRL::ComPtr<ID3D11DepthStencilView>      m_depthStencilView;
        Microsoft::WRL::ComPtr<ID3D11VertexShader>          m_vertexShader;
        Microsoft::WRL::ComPtr<ID3D11PixelShader>           m_pixelShader;
		Microsoft::WRL::ComPtr<ID3D11PixelShader>           m_pixelShaderSolidColor;
        Microsoft::WRL::ComPtr<ID3D11InputLayout>           m_inputLayout;
        Microsoft::WRL::ComPtr<ID3D11Buffer>                m_vertexBuffer;
        Microsoft::WRL::ComPtr<ID3D11Buffer>                m_indexBuffer;
        Microsoft::WRL::ComPtr<ID3D11Buffer>                m_constantBuffer;
		Microsoft::WRL::ComPtr<ID3D11RasterizerState>		m_rasterStateWireFrame;

        DX::ModelViewProjectionConstantBuffer               m_constantBufferData;

        uint32                                              m_indexCount;

        Windows::Foundation::IAsyncAction^					m_renderLoopWorker;
        // Rendering loop timer.
        DX::StepTimer                                       m_timer;

    private:
        ~D3DPanel();
    };
}